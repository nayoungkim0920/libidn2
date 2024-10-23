/*netdb->winsock2 수정*/
#include "config.h"
/* libxml2 - Library for parsing XML documents
 * Copyright (C) 2006-2019 Free Software Foundation, Inc.
 *
 * This file is not part of the GNU gettext program, but is used with
 * GNU gettext.
 *
 * The original copyright notice is as follows:
 */

/*
 * Copyright (C) 1998-2012 Daniel Veillard.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is fur-
 * nished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FIT-
 * NESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * nanoftp.c: basic FTP client support
 *
 *  Reference: RFC 959
 */

#ifdef TESTING
#define STANDALONE
#define HAVE_STDLIB_H
#define HAVE_UNISTD_H
#define HAVE_SYS_SOCKET_H
#define HAVE_NETINET_IN_H
//#define HAVE_NETDB_H     // Commented out
#define HAVE_SYS_TIME_H
#endif /* TESTING */

#define IN_LIBXML
#include "libxml.h"

#ifdef LIBXML_FTP_ENABLED
#include <string.h>

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif

// Replace <netdb.h> with Winsock headers
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <netdb.h>
#endif
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/xmlerror.h>
#include <libxml/uri.h>
#include <libxml/nanoftp.h>
#include <libxml/globals.h>

/* #define DEBUG_FTP 1  */
#ifdef STANDALONE
#ifndef DEBUG_FTP
#define DEBUG_FTP 1
#endif
#endif

#if defined(_WIN32) && !defined(__CYGWIN__)
#include <wsockcompat.h>
#endif

/**
 * A couple portability macros
 */
#ifndef _WINSOCKAPI_
#if !defined(__BEOS__) || defined(__HAIKU__)
#define closesocket(s) close(s)  // No change required
#endif
#endif

#ifdef __BEOS__
#ifndef PF_INET
#define PF_INET AF_INET
#endif
#endif

#ifdef _AIX
#ifdef HAVE_BROKEN_SS_FAMILY
#define ss_family __ss_family
#endif
#endif

#ifndef XML_SOCKLEN_T
#define XML_SOCKLEN_T int   // Change to int for Winsock
#endif

#define FTP_COMMAND_OK		200
#define FTP_SYNTAX_ERROR	500
#define FTP_GET_PASSWD		331
#define FTP_BUF_SIZE		1024

#define XML_NANO_MAX_URLBUF	4096

typedef struct xmlNanoFTPCtxt {
    char *protocol;	/* the protocol name */
    char *hostname;	/* the host name */
    int port;		/* the port */
    char *path;		/* the path within the URL */
    char *user;		/* user string */
    char *passwd;	/* passwd string */
#ifdef SUPPORT_IP6
    struct sockaddr_storage ftpAddr; /* this is large enough to hold IPv6 address*/
#else
    struct sockaddr_in ftpAddr; /* the socket address struct */
#endif
    int passive;	/* currently we support only passive !!! */
    SOCKET controlFd;	/* the file descriptor for the control socket */
    SOCKET dataFd;	/* the file descriptor for the data socket */
    int state;		/* WRITE / READ / CLOSED */
    int returnValue;	/* the protocol return value */
    /* buffer for data received from the control connection */
    char controlBuf[FTP_BUF_SIZE + 1];
    int controlBufIndex;
    int controlBufUsed;
    int controlBufAnswer;
} xmlNanoFTPCtxt, *xmlNanoFTPCtxtPtr;

static int initialized = 0;
static char *proxy = NULL;	/* the proxy name if any */
static int proxyPort = 0;	/* the proxy port if any */
static char *proxyUser = NULL;	/* user for proxy authentication */
static char *proxyPasswd = NULL;/* passwd for proxy authentication */
static int proxyType = 0;	/* uses TYPE or a@b ? */

#ifdef SUPPORT_IP6
static
int have_ipv6(void) {
    int s;

    s = socket (AF_INET6, SOCK_STREAM, 0);
    if (s != INVALID_SOCKET) {  // Change to INVALID_SOCKET for Winsock
	closesocket(s);  // No change required
	return (1);
    }
    return (0);
}
#endif

/**
 * xmlFTPErrMemory:
 * @extra:  extra informations
 *
 * Handle an out of memory condition
 */
static void
xmlFTPErrMemory(const char *extra)
{
    __xmlSimpleError(XML_FROM_FTP, XML_ERR_NO_MEMORY, NULL, NULL, extra);
}

/**
 * xmlNanoFTPInit:
 *
 * Initialize the FTP protocol layer.
 * Currently it just checks for proxy informations,
 * and get the hostname
 */

void
xmlNanoFTPInit(void) {
    const char *env;
#ifdef _WINSOCKAPI_
    WSADATA wsaData;
#endif

    if (initialized)
	return;

#ifdef _WINSOCKAPI_
    if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
	return;
#endif

    proxyPort = 21;
    env = getenv("no_proxy");
    if (env && ((env[0] == '*' ) && (env[1] == 0)))
	return;
    env = getenv("ftp_proxy");
    if (env != NULL) {
	xmlNanoFTPScanProxy(env);
    } else {
	env = getenv("FTP_PROXY");
	if (env != NULL) {
	    xmlNanoFTPScanProxy(env);
	}
    }
    env = getenv("ftp_proxy_user");
    if (env != NULL) {
	proxyUser = xmlMemStrdup(env);
    }
    env = getenv("ftp_proxy_password");
    if (env != NULL) {
	proxyPasswd = xmlMemStrdup(env);
    }
    initialized = 1;
}

/**
 * xmlNanoFTPCleanup:
 *
 * Cleanup the FTP protocol layer. This cleanup proxy informations.
 */

void
xmlNanoFTPCleanup(void) {
    if (proxy != NULL) {
	xmlFree(proxy);
	proxy = NULL;
    }
    if (proxyUser != NULL) {
	xmlFree(proxyUser);
	proxyUser = NULL;
    }
    if (proxyPasswd != NULL) {
	xmlFree(proxyPasswd);
	proxyPasswd = NULL;
    }
#ifdef _WINSOCKAPI_
    if (initialized)
	WSACleanup();
#endif
    initialized = 0;
}

void* xmlNanoFTPNewCtxt(const char *URL) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed\n");
        return NULL; // Handle error appropriately
    }

    xmlNanoFTPCtxtPtr ret;
    char *unescaped;

    ret = (xmlNanoFTPCtxtPtr) xmlMalloc(sizeof(xmlNanoFTPCtxt));
    if (ret == NULL) {
        xmlFTPErrMemory("allocating FTP context");
        WSACleanup(); // Cleanup Winsock
        return NULL;
    }

    memset(ret, 0, sizeof(xmlNanoFTPCtxt));
    ret->port = 21;
    ret->passive = 1;
    ret->returnValue = 0;
    ret->controlBufIndex = 0;
    ret->controlBufUsed = 0;
    ret->controlFd = INVALID_SOCKET;

    unescaped = xmlURIUnescapeString(URL, 0, NULL);
    if (unescaped != NULL) {
        xmlNanoFTPScanURL(ret, unescaped);
        xmlFree(unescaped);
    } else if (URL != NULL) {
        xmlNanoFTPScanURL(ret, URL);
    }

    // Cleanup Winsock before returning
    WSACleanup(); 
    return ret;
}

/**
 * xmlNanoFTPFreeCtxt:
 * @ctx:  an FTP context
 *
 * Frees the context after closing the connection.
 */
void
xmlNanoFTPFreeCtxt(void * ctx) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    if (ctxt == NULL) return;
    if (ctxt->hostname != NULL) xmlFree(ctxt->hostname);
    if (ctxt->protocol != NULL) xmlFree(ctxt->protocol);
    if (ctxt->path != NULL) xmlFree(ctxt->path);
    if (ctxt->user != NULL) xmlFree(ctxt->user);
    if (ctxt->passwd != NULL) xmlFree(ctxt->passwd);
    ctxt->passive = 1;

    if (ctxt->controlFd != INVALID_SOCKET) 
        closesocket(ctxt->controlFd);  // Close the socket
    ctxt->controlFd = INVALID_SOCKET;
    ctxt->controlBufIndex = -1;
    ctxt->controlBufUsed = -1;
    xmlFree(ctxt);
}

/**
 * xmlNanoFTPParseResponse:
 * @buf:  the buffer containing the response
 * @len:  the buffer length
 *
 * Parsing of the server answer, we just extract the code.
 *
 * returns 0 for errors
 *     +XXX for last line of response
 *     -XXX for response to be continued
 */
static int
xmlNanoFTPParseResponse(char *buf, int len) {
    int val = 0;

    if (len < 3) return(-1);
    if ((*buf >= '0') && (*buf <= '9'))
        val = val * 10 + (*buf - '0');
    else
        return(0);
    buf++;
    if ((*buf >= '0') && (*buf <= '9'))
        val = val * 10 + (*buf - '0');
    else
        return(0);
    buf++;
    if ((*buf >= '0') && (*buf <= '9'))
        val = val * 10 + (*buf - '0');
    else
        return(0);
    buf++;
    if (*buf == '-')
        return(-val);
    return(val);
}

/**
 * xmlNanoFTPGetMore:
 * @ctx:  an FTP context
 *
 * Read more information from the FTP control connection
 * Returns the number of bytes read, < 0 indicates an error
 */
static int
xmlNanoFTPGetMore(void *ctx) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    int len;
    int size;

    if ((ctxt == NULL) || (ctxt->controlFd == INVALID_SOCKET)) return(-1);

    if ((ctxt->controlBufIndex < 0) || (ctxt->controlBufIndex > FTP_BUF_SIZE)) {
#ifdef DEBUG_FTP
        xmlGenericError(xmlGenericErrorContext,
		"xmlNanoFTPGetMore : controlBufIndex = %d\n",
		ctxt->controlBufIndex);
#endif
	return(-1);
    }

    if ((ctxt->controlBufUsed < 0) || (ctxt->controlBufUsed > FTP_BUF_SIZE)) {
#ifdef DEBUG_FTP
        xmlGenericError(xmlGenericErrorContext,
		"xmlNanoFTPGetMore : controlBufUsed = %d\n",
		ctxt->controlBufUsed);
#endif
	return(-1);
    }
    if (ctxt->controlBufIndex > ctxt->controlBufUsed) {
#ifdef DEBUG_FTP
        xmlGenericError(xmlGenericErrorContext,
		"xmlNanoFTPGetMore : controlBufIndex > controlBufUsed %d > %d\n",
	       ctxt->controlBufIndex, ctxt->controlBufUsed);
#endif
	return(-1);
    }

    /*
     * First pack the control buffer
     */
    if (ctxt->controlBufIndex > 0) {
	memmove(&ctxt->controlBuf[0], &ctxt->controlBuf[ctxt->controlBufIndex],
		ctxt->controlBufUsed - ctxt->controlBufIndex);
	ctxt->controlBufUsed -= ctxt->controlBufIndex;
	ctxt->controlBufIndex = 0;
    }
    size = FTP_BUF_SIZE - ctxt->controlBufUsed;
    if (size == 0) {
#ifdef DEBUG_FTP
        xmlGenericError(xmlGenericErrorContext,
		"xmlNanoFTPGetMore : buffer full %d \n", ctxt->controlBufUsed);
#endif
	return(0);
    }

    /*
     * Read the amount left on the control connection
     */
    if ((len = recv(ctxt->controlFd, &ctxt->controlBuf[ctxt->controlBufIndex],
		    size, 0)) < 0) {
	__xmlIOErr(XML_FROM_FTP, 0, "recv failed");
	closesocket(ctxt->controlFd); ctxt->controlFd = INVALID_SOCKET;
        return(-1);
    }
#ifdef DEBUG_FTP
    xmlGenericError(xmlGenericErrorContext,
	    "xmlNanoFTPGetMore : read %d [%d - %d]\n", len,
	   ctxt->controlBufUsed, ctxt->controlBufUsed + len);
#endif
    ctxt->controlBufUsed += len;
    ctxt->controlBuf[ctxt->controlBufUsed] = 0;

    return(len);
}

/**
 * xmlNanoFTPReadResponse:
 * @ctx:  an FTP context
 *
 * Read the response from the FTP server after a command.
 * Returns the code number
 */
static int
xmlNanoFTPReadResponse(void *ctx) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    char *ptr, *end;
    int len;
    int res = -1, cur = -1;

    if ((ctxt == NULL) || (ctxt->controlFd == INVALID_SOCKET)) return(-1);

get_more:
    /*
     * Assumes everything up to controlBuf[controlBufIndex] has been read
     * and analyzed.
     */
    len = xmlNanoFTPGetMore(ctx);
    if (len < 0) {
        return(-1);
    }
    if ((ctxt->controlBufUsed == 0) && (len == 0)) {
        return(-1);
    }
    ptr = &ctxt->controlBuf[ctxt->controlBufIndex];
    end = &ctxt->controlBuf[ctxt->controlBufUsed];

#ifdef DEBUG_FTP
    xmlGenericError(xmlGenericErrorContext,
	    "\n<<<\n%s\n--\n", ptr);
#endif
    while (ptr < end) {
        cur = xmlNanoFTPParseResponse(ptr, end - ptr);
	if (cur > 0) {
	    /*
	     * Successfully scanned the control code, scratch
	     * till the end of the line, but keep the index to be
	     * able to analyze the result if needed.
	     */
	    res = cur;
	    ptr += 3;
	    ctxt->controlBufAnswer = ptr - ctxt->controlBuf;
	    while ((ptr < end) && (*ptr != '\n')) ptr++;
	    if (*ptr == '\n') ptr++;
	    if (*ptr == '\r') ptr++;
	    break;
	}
	while ((ptr < end) && (*ptr != '\n')) ptr++;
	if (ptr >= end) {
	    ctxt->controlBufIndex = ctxt->controlBufUsed;
	    goto get_more;
	}
	if (*ptr != '\r') ptr++;
    }

    if (res < 0) goto get_more;
    ctxt->controlBufIndex = ptr - ctxt->controlBuf;
#ifdef DEBUG_FTP
    ptr = &ctxt->controlBuf[ctxt->controlBufIndex];
    xmlGenericError(xmlGenericErrorContext, "\n---\n%s\n--\n", ptr);
#endif

#ifdef DEBUG_FTP
    xmlGenericError(xmlGenericErrorContext, "Got %d\n", res);
#endif
    return(res / 100);
}

/**
 * xmlNanoFTPGetResponse:
 * @ctx:  an FTP context
 *
 * Get the response from the FTP server after a command.
 * Returns the code number
 */

int
xmlNanoFTPGetResponse(void *ctx) {
    int res;

    res = xmlNanoFTPReadResponse(ctx);

    return(res);
}

/**
 * xmlNanoFTPCheckResponse:
 * @ctx:  an FTP context
 *
 * Check if there is a response from the FTP server after a command.
 * Returns the code number, or 0
 */

int
xmlNanoFTPCheckResponse(void *ctx) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    int res;

    if ((ctxt == NULL) || (ctxt->controlFd == INVALID_SOCKET)) return(-1);
    if (ctxt->controlBufIndex >= 0) {
        res = xmlNanoFTPReadResponse(ctx);
        if (res >= 0)
            return res;
    }
    return (xmlNanoFTPGetResponse(ctx));
}

/**
 * xmlNanoFTPInit:
 * @ctx:  an FTP context
 *
 * Initializes the FTP context
 */
void
xmlNanoFTPInit(void *ctx) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    if (ctxt == NULL) return;

    // Additional initialization code for the context if needed
}

static int xmlNanoFTPSendUser(void *ctx) {
    XmlNanoFTPCtxt *ctxt = (XmlNanoFTPCtxt *)ctx;
    char buf[200];
    int len;
    int res;

    if (ctxt->user == NULL)
        snprintf(buf, sizeof(buf), "USER anonymous\r\n");
    else
        snprintf(buf, sizeof(buf), "USER %s\r\n", ctxt->user);

    len = strlen(buf);
#ifdef DEBUG_FTP
    fprintf(stderr, "%s", buf);  // xmlGenericError 대신 fprintf 사용
#endif
    res = send(ctxt->controlFd, buf, len, 0);
    if (res < 0) {
        fprintf(stderr, "send failed\n");  // __xmlIOErr 대신 사용
        return res;
    }
    return 0;
}

static int xmlNanoFTPSendPasswd(void *ctx) {
    XmlNanoFTPCtxt *ctxt = (XmlNanoFTPCtxt *)ctx;
    char buf[200];
    int len;
    int res;

    if (ctxt->passwd == NULL)
        snprintf(buf, sizeof(buf), "PASS anonymous@\r\n");
    else
        snprintf(buf, sizeof(buf), "PASS %s\r\n", ctxt->passwd);

    len = strlen(buf);
#ifdef DEBUG_FTP
    fprintf(stderr, "%s", buf);  // xmlGenericError 대신 fprintf 사용
#endif
    res = send(ctxt->controlFd, buf, len, 0);
    if (res < 0) {
        fprintf(stderr, "send failed\n");  // __xmlIOErr 대신 사용
        return res;
    }
    return 0;
}

int xmlNanoFTPQuit(void *ctx) {
    XmlNanoFTPCtxt *ctxt = (XmlNanoFTPCtxt *)ctx;
    char buf[200];
    int len, res;

    if (ctxt == NULL || ctxt->controlFd == -1) return -1;

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    len = strlen(buf);
#ifdef DEBUG_FTP
    fprintf(stderr, "%s", buf);  // xmlGenericError 대신 fprintf 사용
#endif
    res = send(ctxt->controlFd, buf, len, 0);
    if (res < 0) {
        fprintf(stderr, "send failed\n");  // __xmlIOErr 대신 사용
        return res;
    }
    return 0;
}

int xmlNanoFTPConnect(void *ctx) {
    XmlNanoFTPCtxt *ctxt = (XmlNanoFTPCtxt *)ctx;
    struct hostent *hp;
    int port = 21; // FTP 기본 포트
    int res;
    int addrlen = sizeof(struct sockaddr_in);

    if (ctxt == NULL)
        return -1;
    if (ctxt->user == NULL)
        return -1;

    // FTP 서버 주소 설정
    memset(&ctxt->ftpAddr, 0, sizeof(ctxt->ftpAddr));
    ctxt->ftpAddr.sin_family = AF_INET;
    ctxt->ftpAddr.sin_port = htons(port);
    
    // FTP 서버 IP 주소 확인
    hp = gethostbyname("ftp.example.com");  // FTP 서버 도메인으로 변경하세요.
    if (hp == NULL) {
        fprintf(stderr, "gethostbyname failed\n"); // __xmlIOErr 대신 사용
        return -1;
    }
    
    memcpy(&ctxt->ftpAddr.sin_addr, hp->h_addr, hp->h_length);

    // 소켓 생성
    ctxt->controlFd = socket(AF_INET, SOCK_STREAM, 0);
    if (ctxt->controlFd < 0) {
        fprintf(stderr, "socket failed\n");  // __xmlIOErr 대신 사용
        return -1;
    }

    // FTP 서버에 연결
    if (connect(ctxt->controlFd, (struct sockaddr *)&ctxt->ftpAddr, addrlen) < 0) {
        fprintf(stderr, "Failed to create a connection\n");  // __xmlIOErr 대신 사용
        close(ctxt->controlFd);  // 소켓 닫기
        return -1;
    }

    // 서버로부터 응답 대기 (예: 220 Welcome 메시지)
    char response[512];
    res = recv(ctxt->controlFd, response, sizeof(response) - 1, 0);
    if (res < 0) {
        fprintf(stderr, "recv failed\n");  // __xmlIOErr 대신 사용
        close(ctxt->controlFd);  // 소켓 닫기
        return -1;
    }
    response[res] = '\0'; // 문자열 종료
    printf("Response: %s", response);

    return 0;
}

int main() {
    XmlNanoFTPCtxt ftpCtx;
    ftpCtx.user = "your_username";  // 사용자 이름 입력
    ftpCtx.passwd = "your_password"; // 비밀번호 입력
    ftpCtx.controlFd = -1;

    if (xmlNanoFTPConnect(&ftpCtx) < 0) {
        fprintf(stderr, "Failed to connect to FTP server\n");
        return EXIT_FAILURE;
    }

    if (xmlNanoFTPSendUser(&ftpCtx) < 0) {
        fprintf(stderr, "Failed to send user command\n");
        xmlNanoFTPQuit(&ftpCtx);
        return EXIT_FAILURE;
    }

    if (xmlNanoFTPSendPasswd(&ftpCtx) < 0) {
        fprintf(stderr, "Failed to send password command\n");
        xmlNanoFTPQuit(&ftpCtx);
        return EXIT_FAILURE;
    }

    // 추가 명령어 및 처리 로직을 여기에 추가하세요.

    xmlNanoFTPQuit(&ftpCtx);
    close(ftpCtx.controlFd); // 소켓 닫기
    return EXIT_SUCCESS;
}

void* xmlNanoFTPConnectTo(const char *server, int port) {
    xmlNanoFTPCtxtPtr ctxt;
    int res;

    xmlNanoFTPInit(); // 초기화 함수가 정의되어 있어야 합니다.
    if (server == NULL)
        return NULL;
    if (port <= 0)
        return NULL;

    ctxt = (xmlNanoFTPCtxtPtr) xmlNanoFTPNewCtxt(NULL); // 새로운 FTP 컨텍스트 생성
    if (ctxt == NULL)
        return NULL;

    ctxt->hostname = _strdup(server); // Windows에서는 _strdup 사용
    if (ctxt->hostname == NULL) {
        xmlNanoFTPFreeCtxt(ctxt); // 메모리 해제 함수 정의 필요
        return NULL;
    }

    if (port != 0)
        ctxt->port = port;

    res = xmlNanoFTPConnect(ctxt); // 연결 함수가 정의되어 있어야 합니다.
    if (res < 0) {
        xmlNanoFTPFreeCtxt(ctxt);
        return NULL;
    }
    return ctxt;
}

int xmlNanoFTPCwd(void *ctx, const char *directory) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    char buf[400];
    int len;
    int res;

    if ((ctxt == NULL) || (ctxt->controlFd == INVALID_SOCKET)) return -1;
    if (directory == NULL) return 0;

    snprintf(buf, sizeof(buf), "CWD %s\r\n", directory);
    buf[sizeof(buf) - 1] = 0;
    len = strlen(buf);
#ifdef DEBUG_FTP
    printf("%s", buf); // xmlGenericError 대신 printf로 변경
#endif
    res = send(ctxt->controlFd, buf, len, 0);
    if (res < 0) {
        __xmlIOErr(XML_FROM_FTP, 0, "send failed"); // 오류 처리 함수 정의 필요
        return res;
    }
    res = xmlNanoFTPGetResponse(ctxt); // 응답을 가져오는 함수가 정의되어 있어야 합니다.
    if (res == 4) {
        return -1;
    }
    if (res == 2) return 1;
    if (res == 5) {
        return 0;
    }
    return 0;
}

int xmlNanoFTPDele(void *ctx, const char *file) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    char buf[400];
    int len;
    int res;

    if ((ctxt == NULL) || (ctxt->controlFd == INVALID_SOCKET) || (file == NULL)) return -1;

    snprintf(buf, sizeof(buf), "DELE %s\r\n", file);
    buf[sizeof(buf) - 1] = 0;
    len = strlen(buf);
#ifdef DEBUG_FTP
    printf("%s", buf); // xmlGenericError 대신 printf로 변경
#endif
    res = send(ctxt->controlFd, buf, len, 0);
    if (res < 0) {
        __xmlIOErr(XML_FROM_FTP, 0, "send failed"); // 오류 처리 함수 정의 필요
        return res;
    }
    res = xmlNanoFTPGetResponse(ctxt); // 응답을 가져오는 함수가 정의되어 있어야 합니다.
    if (res == 4) {
        return -1;
    }
    if (res == 2) return 1;
    if (res == 5) {
        return 0;
    }
    return 0;
}

SOCKET xmlNanoFTPGetConnection(void *ctx) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    char buf[200], *cur;
    int len, i;
    int res;
    unsigned char ad[6], *adp, *portp;
    unsigned int temp[6];
    struct sockaddr_in dataAddr;
    int dataAddrLen = sizeof(dataAddr);

    if (ctxt == NULL) return INVALID_SOCKET;

    memset(&dataAddr, 0, sizeof(dataAddr));

    ctxt->dataFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ctxt->dataFd == INVALID_SOCKET) {
        __xmlIOErr(XML_FROM_FTP, 0, "socket failed"); // 오류 처리 함수 정의 필요
        return INVALID_SOCKET;
    }

    if (ctxt->passive) {
        snprintf(buf, sizeof(buf), "PASV\r\n");
        len = strlen(buf);
#ifdef DEBUG_FTP
        printf("%s", buf); // xmlGenericError 대신 printf로 변경
#endif
        res = send(ctxt->controlFd, buf, len, 0);
        if (res < 0) {
            __xmlIOErr(XML_FROM_FTP, 0, "send failed"); // 오류 처리 함수 정의 필요
            closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
            return INVALID_SOCKET;
        }
        res = xmlNanoFTPReadResponse(ctx); // 응답을 읽는 함수가 정의되어 있어야 합니다.
        if (res != 2) {
            closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
            return INVALID_SOCKET;
        }
        
        cur = &ctxt->controlBuf[ctxt->controlBufAnswer];
        if (sscanf(cur, "%u,%u,%u,%u,%u,%u", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5]) != 6) {
            __xmlIOErr(XML_FROM_FTP, XML_FTP_PASV_ANSWER, "Invalid answer to PASV\n"); // 오류 처리 함수 정의 필요
            closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
            return INVALID_SOCKET;
        }
        
        for (i = 0; i < 6; i++) ad[i] = (unsigned char)(temp[i] & 0xff);
        memcpy(&dataAddr.sin_addr, &ad[0], 4);
        dataAddr.sin_port = htons((unsigned short)((temp[4] << 8) + temp[5])); // 포트 설정
    } else {
        getsockname(ctxt->dataFd, (struct sockaddr*)&dataAddr, &dataAddrLen);
        dataAddr.sin_port = 0;

        if (bind(ctxt->dataFd, (struct sockaddr*)&dataAddr, dataAddrLen) < 0) {
            __xmlIOErr(XML_FROM_FTP, 0, "bind failed"); // 오류 처리 함수 정의 필요
            closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
            return INVALID_SOCKET;
        }
        if (listen(ctxt->dataFd, 1) < 0) {
            __xmlIOErr(XML_FROM_FTP, 0, "listen failed"); // 오류 처리 함수 정의 필요
            closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
            return INVALID_SOCKET;
        }
    }

    // 연결
    if (connect(ctxt->dataFd, (struct sockaddr*)&dataAddr, dataAddrLen) < 0) {
        __xmlIOErr(XML_FROM_FTP, 0, "Failed to create a data connection"); // 오류 처리 함수 정의 필요
        closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
        return INVALID_SOCKET;
    }

    return ctxt->dataFd;
}

int xmlNanoFTPCloseConnection(void *ctx) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    int res;
    fd_set rfd, efd;
    struct timeval tv;

    if ((ctxt == NULL) || (ctxt->controlFd == INVALID_SOCKET)) return(-1);

    closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
    tv.tv_sec = 15;
    tv.tv_usec = 0;
    FD_ZERO(&rfd);
    FD_SET(ctxt->controlFd, &rfd);
    FD_ZERO(&efd);
    FD_SET(ctxt->controlFd, &efd);
    res = select(ctxt->controlFd + 1, &rfd, NULL, &efd, &tv);
    if (res < 0) {
#ifdef DEBUG_FTP
        perror("select");
#endif
        closesocket(ctxt->controlFd); ctxt->controlFd = INVALID_SOCKET;
        return(-1);
    }
    if (res == 0) {
#ifdef DEBUG_FTP
        fprintf(stderr, "xmlNanoFTPCloseConnection: timeout\n");
#endif
        closesocket(ctxt->controlFd); ctxt->controlFd = INVALID_SOCKET;
    } else {
        res = xmlNanoFTPGetResponse(ctxt);
        if (res != 2) {
            closesocket(ctxt->controlFd); ctxt->controlFd = INVALID_SOCKET;
            return(-1);
        }
    }
    return(0);
}

static int xmlNanoFTPParseList(const char *list, ftpListCallback callback, void *userData) {
    const char *cur = list;
    char filename[151];
    char attrib[11];
    char owner[11];
    char group[11];
    char month[4];
    int year = 0;
    int minute = 0;
    int hour = 0;
    int day = 0;
    unsigned long size = 0;
    int links = 0;
    int i;

    if (!strncmp(cur, "total", 5)) {
        cur += 5;
        while (*cur == ' ') cur++;
        while ((*cur >= '0') && (*cur <= '9'))
            links = (links * 10) + (*cur++ - '0');
        while ((*cur == ' ') || (*cur == '\n')  || (*cur == '\r'))
            cur++;
        return(cur - list);
    } else if (*list == '+') {
        return(0);
    } else {
        while ((*cur == ' ') || (*cur == '\n')  || (*cur == '\r'))
            cur++;
        if (*cur == 0) return(0);
        i = 0;
        while (*cur != ' ') {
            if (i < 10)
                attrib[i++] = *cur;
            cur++;
            if (*cur == 0) return(0);
        }
        attrib[10] = 0;
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        while ((*cur >= '0') && (*cur <= '9'))
            links = (links * 10) + (*cur++ - '0');
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        i = 0;
        while (*cur != ' ') {
            if (i < 10)
                owner[i++] = *cur;
            cur++;
            if (*cur == 0) return(0);
        }
        owner[i] = 0;
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        i = 0;
        while (*cur != ' ') {
            if (i < 10)
                group[i++] = *cur;
            cur++;
            if (*cur == 0) return(0);
        }
        group[i] = 0;
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        while ((*cur >= '0') && (*cur <= '9'))
            size = (size * 10) + (*cur++ - '0');
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        i = 0;
        while (*cur != ' ') {
            if (i < 3)
                month[i++] = *cur;
            cur++;
            if (*cur == 0) return(0);
        }
        month[i] = 0;
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        while ((*cur >= '0') && (*cur <= '9'))
            day = (day * 10) + (*cur++ - '0');
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        if ((cur[1] == 0) || (cur[2] == 0)) return(0);
        if ((cur[1] == ':') || (cur[2] == ':')) {
            while ((*cur >= '0') && (*cur <= '9'))
                hour = (hour * 10) + (*cur++ - '0');
            if (*cur == ':') cur++;
            while ((*cur >= '0') && (*cur <= '9'))
                minute = (minute * 10) + (*cur++ - '0');
        } else {
            while ((*cur >= '0') && (*cur <= '9'))
                year = (year * 10) + (*cur++ - '0');
        }
        while (*cur == ' ') cur++;
        if (*cur == 0) return(0);
        i = 0;
        while ((*cur != '\n')  && (*cur != '\r')) {
            if (i < 150)
                filename[i++] = *cur;
            cur++;
            if (*cur == 0) return(0);
        }
        filename[i] = 0;
        if ((*cur != '\n') && (*cur != '\r'))
            return(0);
        while ((*cur == '\n')  || (*cur == '\r'))
            cur++;
    }
    if (callback != NULL) {
        callback(userData, filename, attrib, owner, group, size, links,
            year, month, day, hour, minute);
    }
    return(cur - list);
}

int xmlNanoFTPList(void *ctx, ftpListCallback callback, void *userData, const char *filename) {
    xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
    char buf[4096 + 1];
    int len, res;
    int indx = 0, base;
    fd_set rfd, efd;
    struct timeval tv;

    if (ctxt == NULL) return (-1);
    if (filename == NULL) {
        if (xmlNanoFTPCwd(ctxt, ctxt->path) < 1)
            return(-1);
        ctxt->dataFd = xmlNanoFTPGetConnection(ctxt);
        if (ctxt->dataFd == INVALID_SOCKET)
            return(-1);
        snprintf(buf, sizeof(buf), "LIST -L\r\n");
    } else {
        if (filename[0] != '/') {
            if (xmlNanoFTPCwd(ctxt, ctxt->path) < 1)
                return(-1);
        }
        ctxt->dataFd = xmlNanoFTPGetConnection(ctxt);
        if (ctxt->dataFd == INVALID_SOCKET)
            return(-1);
        snprintf(buf, sizeof(buf), "LIST -L %s\r\n", filename);
    }
    buf[sizeof(buf) - 1] = 0;
    len = strlen(buf);
#ifdef DEBUG_FTP
    fprintf(stderr, "%s", buf);
#endif
    res = send(ctxt->controlFd, buf, len, 0);
    if (res < 0) {
        __xmlIOErr(XML_FROM_FTP, 0, "send failed");
        closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
        return(res);
    }
    res = xmlNanoFTPReadResponse(ctxt);
    if (res != 1) {
        closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
        return(-res);
    }

    do {
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        FD_ZERO(&rfd);
        FD_SET(ctxt->dataFd, &rfd);
        FD_ZERO(&efd);
        FD_SET(ctxt->dataFd, &efd);
        res = select(ctxt->dataFd + 1, &rfd, NULL, &efd, &tv);
        if (res < 0) {
#ifdef DEBUG_FTP
            perror("select");
#endif
            closesocket(ctxt->dataFd); ctxt->dataFd = INVALID_SOCKET;
            return(-1);
        }
        if (res == 0) {
            if (indx > 0) {
                buf[indx] = 0;
                base = xmlNanoFTPParseList(buf, callback, userData);
                if (base <= 0) break;
                memmove(buf, &buf[base], indx - base);
                indx -= base;
            }
            continue;
        }
        res = recv(ctxt->dataFd, &buf[indx], sizeof(buf) - indx - 1, 0);
        if (res <= 0) break;
        indx += res;
        buf[indx] = 0;
        base = xmlNanoFTPParseList(buf, callback, userData);
        if (base <= 0) break;
        memmove(buf, &buf[base], indx - base);
        indx -= base;
    } while (1);

    if (indx > 0) {
        buf[indx] = 0;
        xmlNanoFTPParseList(buf, callback, userData);
    }
    closesocket(ctxt->dataFd);
    ctxt->dataFd = INVALID_SOCKET;
    res = xmlNanoFTPGetResponse(ctxt);
    if (res != 2) {
        return(-res);
    }
    return(0);
}