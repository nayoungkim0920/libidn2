/* test-lookup.c --- Self tests for IDNA processing
   Copyright (C) 2011 Simon Josefsson

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>

#include <idn2.h>

struct idna
{
  const char *in;
  const char *out;
  int rc;
};

static const struct idna idna[] = {
  /* These comes from http://www.iana.org/domains/root/db see
     gen-idn-tld-tv.pl */
  {"\xe6\xb5\x8b\xe8\xaf\x95", "xn--0zwm56d" },
  {"\xe0\xa4\xaa\xe0\xa4\xb0\xe0\xa5\x80\xe0\xa4\x95\xe0\xa5\x8d\xe0\xa4\xb7\xe0\xa4\xbe", "xn--11b5bs3a9aj6g" },
  {"\xed\x95\x9c\xea\xb5\xad", "xn--3e0b707e" },
  {"\xe0\xa6\xad\xe0\xa6\xbe\xe0\xa6\xb0\xe0\xa6\xa4", "xn--45brj9c" },
  {"\xd0\x98\xd0\xa1\xd0\x9f\xd0\xab\xd0\xa2\xd0\x90\xd0\x9d\xd0\x98\xd0\x95", "xn--80akhbyknj4f", IDN2_DISALLOWED }, /* iana bug */
  {"испытание", "xn--80akhbyknj4f" }, /* corrected */
  {"\xd0\xa1\xd0\xa0\xd0\x91", "xn--90a3ac", IDN2_DISALLOWED }, /* iana bug */
  {"срб", "xn--90a3ac" }, /* corrected */
  {"\xed\x85\x8c\xec\x8a\xa4\xed\x8a\xb8", "xn--9t4b11yi5a" },
  {"\xe0\xae\x9a\xe0\xae\xbf\xe0\xae\x99\xe0\xaf\x8d\xe0\xae\x95\xe0\xae\xaa\xe0\xaf\x8d\xe0\xae\xaa\xe0\xaf\x82\xe0\xae\xb0\xe0\xaf\x8d", "xn--clchc0ea0b2g2a9gcd" },
  {"\xd7\x98\xd7\xa2\xd7\xa1\xd7\x98", "xn--deba0ad" },
  {"\xe4\xb8\xad\xe5\x9b\xbd", "xn--fiqs8s" },
  {"\xe4\xb8\xad\xe5\x9c\x8b", "xn--fiqz9s" },
  {"\xe0\xb0\xad\xe0\xb0\xbe\xe0\xb0\xb0\xe0\xb0\xa4\xe0\xb1\x8d", "xn--fpcrj9c3d" },
  {"\xe0\xb6\xbd\xe0\xb6\x82\xe0\xb6\x9a\xe0\xb7\x8f", "xn--fzc2c9e2c" },
  {"\xe6\xb8\xac\xe8\xa9\xa6", "xn--g6w251d" },
  {"\xe0\xaa\xad\xe0\xaa\xbe\xe0\xaa\xb0\xe0\xaa\xa4", "xn--gecrj9c" },
  {"\xe0\xa4\xad\xe0\xa4\xbe\xe0\xa4\xb0\xe0\xa4\xa4", "xn--h2brj9c" },
  {"\xd8\xa2\xd8\xb2\xd9\x85\xd8\xa7\xdb\x8c\xd8\xb4\xdb\x8c", "xn--hgbk6aj7f53bba" },
  {"\xe0\xae\xaa\xe0\xae\xb0\xe0\xae\xbf\xe0\xae\x9f\xe0\xaf\x8d\xe0\xae\x9a\xe0\xaf\x88", "xn--hlcj6aya9esc7a" },
  {"\xe9\xa6\x99\xe6\xb8\xaf", "xn--j6w193g" },
  {"\xce\x94\xce\x9f\xce\x9a\xce\x99\xce\x9c\xce\x89", "xn--jxalpdlp", IDN2_DISALLOWED }, /* iana bug */
  {"δοκιμή", "xn--jxalpdlp" },
  {"\xd8\xa5\xd8\xae\xd8\xaa\xd8\xa8\xd8\xa7\xd8\xb1", "xn--kgbechtv" },
  {"\xe5\x8f\xb0\xe6\xb9\xbe", "xn--kprw13d" },
  {"\xe5\x8f\xb0\xe7\x81\xa3", "xn--kpry57d" },
  {"\xd8\xa7\xd9\x84\xd8\xac\xd8\xb2\xd8\xa7\xd8\xa6\xd8\xb1", "xn--lgbbat1ad8j" },
  {"\xd8\xb9\xd9\x85\xd8\xa7\xd9\x86", "xn--mgb9awbf" },
  {"\xd8\xa7\xdb\x8c\xd8\xb1\xd8\xa7\xd9\x86", "xn--mgba3a4f16a" },
  {"\xd8\xa7\xd9\x85\xd8\xa7\xd8\xb1\xd8\xa7\xd8\xaa", "xn--mgbaam7a8h" },
  {"\xd8\xa7\xd9\x84\xd8\xa7\xd8\xb1\xd8\xaf\xd9\x86", "xn--mgbayh7gpa" },
  {"\xd8\xa8\xda\xbe\xd8\xa7\xd8\xb1\xd8\xaa", "xn--mgbbh1a71e" },
  {"\xd8\xa7\xd9\x84\xd9\x85\xd8\xba\xd8\xb1\xd8\xa8", "xn--mgbc0a9azcg" },
  {"\xd8\xa7\xd9\x84\xd8\xb3\xd8\xb9\xd9\x88\xd8\xaf\xd9\x8a\xd8\xa9", "xn--mgberp4a5d4ar" },
  {"\xe1\x83\x92\xe1\x83\x94", "xn--node" },
  {"\xe0\xb9\x84\xe0\xb8\x97\xe0\xb8\xa2", "xn--o3cw4h" },
  {"\xd8\xb3\xd9\x88\xd8\xb1\xd9\x8a\xd8\xa9", "xn--ogbpf8fl" },
  {"\xd0\xa0\xd0\xa4", "xn--p1ai", IDN2_DISALLOWED }, /* iana bug */
  {"рф", "xn--p1ai" }, /* corrected */
  {"\xd8\xaa\xd9\x88\xd9\x86\xd8\xb3", "xn--pgbs0dh" },
  {"\xe0\xa8\xad\xe0\xa8\xbe\xe0\xa8\xb0\xe0\xa8\xa4", "xn--s9brj9c" },
  {"\xd9\x85\xd8\xb5\xd8\xb1", "xn--wgbh1c" },
  {"\xd9\x82\xd8\xb7\xd8\xb1", "xn--wgbl6a" },
  {"\xe0\xae\x87\xe0\xae\xb2\xe0\xae\x99\xe0\xaf\x8d\xe0\xae\x95\xe0\xaf\x88", "xn--xkc2al3hye2a" },
  {"\xe0\xae\x87\xe0\xae\xa8\xe0\xaf\x8d\xe0\xae\xa4\xe0\xae\xbf\xe0\xae\xaf\xe0\xae\xbe", "xn--xkc2dl3a5ee0h" },
  {"\xe6\x96\xb0\xe5\x8a\xa0\xe5\x9d\xa1", "xn--yfro4i67o" },
  {"\xd9\x81\xd9\x84\xd8\xb3\xd8\xb7\xd9\x8a\xd9\x86", "xn--ygbi2ammx" },
  {"\xe3\x83\x86\xe3\x82\xb9\xe3\x83\x88", "xn--zckzah" },
  /* end of IANA strings */
  /* the following comes from IDNA2003 libidn */
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xc3\xad\x64\x6e", "example.xn--dn-mja"
   /* 1-1-1 Has an IDN in just the TLD */
  },
  {"\xc3\xab\x78\x2e\xc3\xad\x64\x6e", "xn--x-ega.xn--dn-mja"
   /* 1-1-2 Has an IDN in the TLD and SLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xc3\xa5\xc3\xbe\xc3\xa7",
   "example.xn--5cae2e"
   /* 1-2-1 Latin-1 TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xc4\x83\x62\xc4\x89",
   "example.xn--b-rhat"
   /* 1-2-2 Latin Extended A TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xc8\xa7\xc6\x80\xc6\x88",
   "example.xn--lhaq98b"
   /* 1-2-3 Latin Extended B TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe1\xb8\x81\xe1\xb8\x83\xe1\xb8\x89",
   "example.xn--2fges"
   /* 1-2-4 Latin Extended Additional TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe4\xb8\xbf\xe4\xba\xba\xe5\xb0\xb8",
   "example.xn--xiqplj17a"
   /* 1-3-1 Han TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe3\x81\x8b\xe3\x81\x8c\xe3\x81\x8d",
   "example.xn--u8jcd"
   /* 1-3-2 Hiragana TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe3\x82\xab\xe3\x82\xac\xe3\x82\xad",
   "example.xn--lckcd"
   /* 1-3-3 Katakana TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe1\x84\x80\xe1\x85\xa1\xe1\x86\xa8",
   "example.xn--p39a",
   IDN2_NOT_NFC
   /* 1-3-4 Hangul Jamo TLD */
   /* Don't resolve as example.xn--ypd8qrh */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xea\xb1\xa9\xeb\x93\x86\xec\x80\xba",
   "example.xn--o69aq2nl0j"
   /* 1-3-5 Hangul TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xea\x80\x8a\xea\x80\xa0\xea\x8a\xb8",
   "example.xn--6l7arby7j"
   /* 1-3-6 Yi TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xce\xb1\xce\xb2\xce\xb3",
   "example.xn--mxacd"
   /* 1-3-7 Greek TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe1\xbc\x82\xe1\xbc\xa6\xe1\xbd\x95",
   "example.xn--fng7dpg"
   /* 1-3-8 Greek Extended TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xd0\xb0\xd0\xb1\xd0\xb2",
   "example.xn--80acd"
   /* 1-3-9 Cyrillic TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xd5\xa1\xd5\xa2\xd5\xa3",
   "example.xn--y9acd"
   /* 1-3-10 Armeian TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe1\x83\x90\xe1\x83\x91\xe1\x83\x92",
   "example.xn--lodcd"
   /* 1-3-11 Georgian TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe2\x88\xa1\xe2\x86\xba\xe2\x8a\x82",
   "example.xn--b7gxomk",
   /* 1-4-1 Symbols TLD */
   IDN2_DISALLOWED /* valid IDNA2003 invalid IDNA2008 */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xa4\x95\xe0\xa4\x96\xe0\xa4\x97",
   "example.xn--11bcd"
   /* 1-5-1 Devanagari TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xa6\x95\xe0\xa6\x96\xe0\xa6\x97",
   "example.xn--p5bcd"
   /* 1-5-2 Bengali TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xa8\x95\xe0\xa8\x96\xe0\xa8\x97",
   "example.xn--d9bcd"
   /* 1-5-3 Gurmukhi TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xaa\x95\xe0\xaa\x96\xe0\xaa\x97",
   "example.xn--0dccd"
   /* 1-5-4 Gujarati TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xac\x95\xe0\xac\x96\xe0\xac\x97",
   "example.xn--ohccd"
   /* 1-5-5 Oriya TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xae\x95\xe0\xae\x99\xe0\xae\x9a",
   "example.xn--clcid"
   /* 1-5-6 Tamil TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xb0\x95\xe0\xb0\x96\xe0\xb0\x97",
   "example.xn--zoccd"
   /* 1-5-7 Telugu TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xb2\x95\xe0\xb2\x96\xe0\xb2\x97",
   "example.xn--nsccd"
   /* 1-5-8 Kannada TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xb4\x95\xe0\xb4\x96\xe0\xb4\x97",
   "example.xn--bwccd"
   /* 1-5-9 Malayalam TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xb6\x9a\xe0\xb6\x9b\xe0\xb6\x9c",
   "example.xn--3zccd"
   /* 1-5-10 Sinhala TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xb8\x81\xe0\xb8\x82\xe0\xb8\x83",
   "example.xn--12ccd"
   /* 1-5-11 Thai TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xba\x81\xe0\xba\x82\xe0\xba\x84",
   "example.xn--p6ccg"
   /* 1-5-12 Lao TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe0\xbd\x80\xe0\xbd\x81\xe0\xbd\x82",
   "example.xn--5cdcd"
   /* 1-5-13 Tibetan TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe1\x80\x80\xe1\x80\x81\xe1\x80\x82",
   "example.xn--nidcd"
   /* 1-5-14 Myanmar TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe1\x9e\x80\xe1\x9e\x81\xe1\x9e\x82",
   "example.xn--i2ecd"
   /* 1-5-15 Khmer TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xe1\xa0\xa0\xe1\xa0\xa1\xe1\xa0\xa2",
   "example.xn--26ecd"
   /* 1-5-16 Mongolian TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xd8\xa7\xd8\xa8\xd8\xa9",
   "example.xn--mgbcd"
   /* 1-6-1 Arabic TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xd7\x90\xd7\x91\xd7\x92",
   "example.xn--4dbcd"
   /* 1-6-2 Hebrew TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xdc\x90\xdc\x91\xdc\x92",
   "example.xn--9mbcd"
   /* 1-6-3 Syriac TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\x61\x62\x63\xe3\x82\xab\xe3\x82\xac\xe3\x82\xad",
   "example.xn--abc-mj4bfg"
   /* 1-7-1 ASCII and non-Latin TLD */
  },
  {"\x65\x78\x61\x6d\x70\x6c\x65\x2e\xc3\xa5\xc3\xbe\xc3\xa7\xe3\x82\xab\xe3\x82\xac\xe3\x82\xad",
   "example.xn--5cae2e328wfag"
   /* 1-7-2 Latin (non-ASCII) and non-Latin TLD */
  },
  {"\xc3\xad\x21\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_DISALLOWED
   /* 2-3-1-1 Includes ! before Nameprep */
   /* Don't resolve as xn--!dn-qma.example */
  },
  {"\xc3\xad\x24\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_DISALLOWED
   /* 2-3-1-2 Includes $ before Nameprep */
   /* Don't resolve as xn--$dn-qma.example */
  },
  {"\xc3\xad\x2b\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_DISALLOWED
   /* 2-3-1-3 Includes + before Nameprep */
   /* Don't resolve as xn--+dn-qma.example */
  },
  {"\x2d\xc3\xad\x31\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn---1dn-vpa.example"
   /* 2-3-2-1 Leading hyphen before Nameprep */
   /* Don't resolve as xn---1dn-vpa.example */
   /* Valid according to IDNA2008-lookup! */
  },
  {"\xc3\xad\x31\x64\x6e\x2d\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--1dn--upa.example"
   /* 2-3-2-2 Trailing hyphen before Nameprep */
   /* Don't resolve as xn--1dn--upa.example */
   /* Valid according to IDNA2008-lookup! */
  },
  {"\xc3\xad\xef\xbc\x8b\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_DISALLOWED
   /* 2-3-3-1 Gets a + after Nameprep */
   /* Don't resolve as xn--dn-mja0331x.example */
  },
  {"\xc3\xad\xe2\x81\xbc\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_DISALLOWED
   /* 2-3-3-2 Gets a = after Nameprep */
   /* Don't resolve as xn--dn-mja0343a.example */
  },
  {"\xef\xb9\xa3\xc3\xad\x32\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_DISALLOWED
   /* 2-3-4-1 Leading hyphen after Nameprep */
   /* Don't resolve as xn--2dn-qma32863a.example */
   /* Don't resolve as xn---2dn-vpa.example */
  },
  {"\xc3\xad\x32\x64\x6e\xef\xbc\x8d\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_DISALLOWED
   /* 2-3-4-2 Trailing hyphen after Nameprep */
   /* Don't resolve as xn--2dn-qma79363a.example */
   /* Don't resolve as xn--2dn--upa.example */
  },
  {"\xc2\xb9\x31\x2e\x65\x78\x61\x6d\x70\x6c\x65", "11.example",
   IDN2_DISALLOWED
   /* 2-4-1 All-ASCII check, Latin */
  },
  {"\xe2\x85\xa5\x76\x69\x2e\x65\x78\x61\x6d\x70\x6c\x65", "vivi.example",
   IDN2_DISALLOWED
   /* 2-4-2 All-ASCII check, symbol */
  },
  {"\xc3\x9f\x73\x73\x2e\x65\x78\x61\x6d\x70\x6c\x65", "xn--ss-fia.example"
   /* 2-4-3 All-ASCII check, sharp S */
   /* Different output in IDNA2008-lookup compared to IDNA2003! */
  },
  {"\x78\x6e\x2d\x2d\xc3\xaf\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65", "",
   IDN2_2HYPHEN
   /* 2-5-1 ACE prefix before Nameprep, body */
   /* Don't resolve as xn--xn--dn-sja.example */
   /* Don't resolve as xn--dn-sja.example */
  },
  {"\xe2\x85\xb9\x6e\x2d\x2d\xc3\xa4\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_2HYPHEN
   /* 2-5-2 ACE prefix before Nameprep, prefix */
   /* Don't resolve as xn--xn--dn-uia.example */
   /* Don't resolve as xn--dn-uia.example */
  },
  {"", ""
   /* 2-8-1 Zero-length label after Nameprep */
   /* Don't resolve as xn--kba.example */
   /* Don't resolve as xn--.example */
  },
  {"\x33\x30\x30\x32\x2d\x74\x65\x73\x74\xe3\x80\x82\xc3\xad\x64\x6e",
   "3002-test.xn--dn-mja",
   IDN2_DISALLOWED
   /* 2-9-1 U+3002 acts as a label separator */
   /* Don't resolve as xn--3002-testdn-wcb2087m.example */
   /* Not valid in IDNA2008! */
  },
  {"\x66\x66\x30\x65\x2d\x74\x65\x73\x74\xef\xbc\x8e\xc3\xad\x64\x6e",
   "ff0e-test.xn--dn-mja",
   IDN2_DISALLOWED
   /* 2-9-2 U+FF0E acts as a label separator */
   /* Don't resolve as xn--ff0e-testdn-wcb45865f.example */
   /* Not valid in IDNA2008! */
  },
  {"\x66\x66\x36\x31\x2d\x74\x65\x73\x74\xef\xbd\xa1\xc3\xad\x64\x6e",
   "ff61-test.xn--dn-mja",
   IDN2_DISALLOWED
   /* 2-9-3 U+FF61 acts as a label separator */
   /* Don't resolve as xn--ff61-testdn-wcb33975f.example */
   /* Not valid in IDNA2008! */
  },
  {"\x30\x30\x61\x64\x6f\x75\x74\xc2\xad\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--00adoutdn-m5a.example", IDN2_DISALLOWED
   /* 4-1-1-1 00adout<00AD><00ED>dn.example -> 00adout<00ED>dn.example */
   /* Don't resolve as xn--00adoutdn-cna81e.example */
   /* Not valid in IDNA2008! */
  },
#if 0 /* FIXME: implement CONTEXTJ rule */
  {"\x32\x30\x30\x64\x6f\x75\x74\xe2\x80\x8d\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--200doutdn-m5a.example"
   /* 4-1-1-2 200dout<200D><00ED>dn.example -> 200dout<00ED>dn.example */
   /* Don't resolve as xn--200doutdn-m5a1678f.example */
  },
#endif
  {"\x73\x69\x6d\x70\x6c\x65\x63\x61\x70\x44\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--simplecapddn-1fb.example", IDN2_DISALLOWED
   /* 4-1-2-1 simplecap<0044><00ED>dn.example -> simplecap<0064><00ED>dn.example */
   /* Uppercase not valid in IDNA2008! */
  },
  {"\x6c\x61\x74\x69\x6e\x74\x6f\x67\x72\x65\x65\x6b\xc2\xb5\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--latintogreekdn-cmb716i.example", IDN2_DISALLOWED
   /* 4-1-2-2 latintogreek<00B5><00ED>dn.example -> latintogreek<03BC><00ED>dn.example */
   /* Don't resolve as xn--latintogreekdn-cxa01g.example */
   /* B5 not valid in IDNA2008! */
  },
  {"\x6c\x61\x74\x69\x6e\x65\x78\x74\xc3\x87\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--latinextdn-v6a6e.example", IDN2_DISALLOWED
   /* 4-1-2-3 latinext<00C7><00ED>dn.example -> latinext<00E7><00ED>dn.example */
   /* Don't resolve as xn--latinextdn-twa07b.example */
   /* C7 not valid in IDNA2008! */
  },
  {"\x73\x68\x61\x72\x70\x73\xc3\x9f\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--sharpsdn-vya4l.example"
   /* 4-1-2-4 sharps<00DF><00ED>dn.example -> sharpsss<00ED>dn.example */
   /* Don't resolve as xn--sharpsdn-vya4l.example */
   /* Changed in IDNA2008! */
  },
  {"\x74\x75\x72\x6b\x69\x73\x68\x69\xc4\xb0\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--turkishiidn-wcb701e.example", IDN2_DISALLOWED
   /* 4-1-2-5 turkishi<0130><00ED>dn.example -> turkishi<0069><0307><00ED>dn.example */
   /* Don't resolve as xn--turkishidn-r8a71f.example */
   /* U+0130 not valid in IDNA2008! */
  },
  {"\x65\x78\x70\x74\x77\x6f\xc5\x89\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--exptwondn-m5a502c.example", IDN2_DISALLOWED
   /* 4-1-2-6 exptwo<0149><00ED>dn.example -> exptwo<02BC><006E><00ED>dn.example */
   /* Don't resolve as xn--exptwodn-h2a33g.example */
   /* U+0149 not valid in IDNA2008 */
  },
  {"\x61\x64\x64\x66\x6f\x6c\x64\xcf\x92\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--addfolddn-m5a121f.example", IDN2_DISALLOWED
   /* 4-1-2-7 addfold<03D2><00ED>dn.example -> addfold<03C5><00ED>dn.example */
   /* Don't resolve as xn--addfolddn-m5a462f.example */
   /* U+03D2 not valid in IDNA2008 */
  },
  {"\x65\x78\x70\x74\x68\x72\x65\x65\xe1\xbd\x92\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--expthreedn-r8a5844g.example"
   /* 4-1-2-8 expthree<1F52><00ED>dn.example -> expthree<03C5><0313><0300><00ED>dn.example */
  },
  {"\x6e\x6f\x6e\x62\x6d\x70\xf0\x90\x90\x80\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--nonbmpdn-h2a34747d.example", IDN2_DISALLOWED
   /* 4-1-2-9 nonbmp<10400><00ED>dn.example -> nonbmp<10428><00ED>dn.example */
   /* Don't resolve as xn--nonbmpdn-h2a37046d.example */
   /* U+10400 not valid under IDNA2008 */
  },
  {"\x6e\x6f\x6e\x62\x6d\x70\x74\x6f\x61\x73\x63\x69\x69\xf0\x9d\x90\x80\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--nonbmptoasciiadn-msb.example", IDN2_DISALLOWED
   /* 4-1-2-10 nonbmptoascii<1D400><00ED>dn.example -> nonbmptoasciia<00ED>dn.example */
   /* Don't resolve as xn--nonbmptoasciidn-hpb54112i.example */
   /* U+1d400 not valid IDNA2008 */
  },
  {"\x72\x65\x67\x63\x6f\x6d\x62\x65\xcc\x81\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--regcombdn-h4a8b.example", IDN2_NOT_NFC
   /* 4-2-1-1 regcomb<0065><0301><00ED>dn.example -> regcomb<00E9><00ED>dn.example */
   /* Don't resolve as xn--regcombedn-r8a794d.example */
   /* Input not NFC */
  },
  {"regcombéídn.example", "xn--regcombdn-h4a8b.example"
   /* NFKC of previous */
  },
  {"\x63\x6f\x6d\x62\x61\x6e\x64\x63\x61\x73\x65\x45\xcc\x81\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--combandcasedn-lhb4d.example", IDN2_NOT_NFC
   /* 4-2-1-2 combandcase<0045><0301><00ED>dn.example -> combandcase<00E9><00ED>dn.example */
   /* Don't resolve as xn--combandcaseedn-cmb526f.example */
  },
  {"combandcaseÉídn.example",
   "xn--combandcasedn-lhb4d.example", IDN2_DISALLOWED
   /* NFKC of previous, uppercase not IDNA2008-valid */
  },
  {"combandcaseéídn.example",
   "xn--combandcasedn-lhb4d.example"
   /* Lower case of previous */
  },
  {"\x61\x64\x6a\x63\x6f\x6d\x62\xc2\xba\xcc\x81\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--adjcombdn-m5a9d.example", IDN2_DISALLOWED
   /* 4-2-1-3 adjcomb<00BA><0301><00ED>dn.example -> adjcomb<00F3><00ED>dn.example */
   /* Don't resolve as xn--adjcombdn-1qa57cp3r.example */
   /* U+00BA not IDNA2008-valid */
  },
  {"\x65\x78\x74\x63\x6f\x6d\x62\x6f\x63\xcc\x81\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--extcombodn-r8a52a.example", IDN2_NOT_NFC
   /* 4-2-1-4 extcombo<0063><0301><00ED>dn.example -> extcombo<0107><00ED>dn.example */
   /* Don't resolve as xn--extcombocdn-wcb920e.example */
  },
  {"extcomboćídn.example",
   "xn--extcombodn-r8a52a.example"
   /* NFKC of previous */
  },
  {"\x64\x6f\x75\x62\x6c\x65\x64\x69\x61\x63\x31\x75\xcc\x88\xcc\x81\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--doublediac1dn-6ib836a.example", IDN2_NOT_NFC
   /* 4-2-1-5 doublediac1<0075><0308><0301><00ED>dn.example -> doublediac2<01D8><00ED>dn.example */
   /* Don't resolve as xn--doublediac1udn-cmb526fnd.example */
  },
  {"doublediac1ǘídn.example",
   "xn--doublediac1dn-6ib836a.example"
   /* NFKC of previous */
  },
  {"\x64\x6f\x75\x62\x6c\x65\x64\x69\x61\x63\x32\x75\xcc\x81\xcc\x88\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--doublediac2dn-6ib8qs73a.example", IDN2_NOT_NFC
   /* 4-2-1-6 doublediac2<0075><0301><0308><00ED>dn.example -> doublediac2<01D8><00ED>dn.example */
   /* Don't resolve as xn--doublediac2udn-cmb526fod.example */
  },
  {"doublediac2ú̈ídn.example",
   "xn--doublediac2dn-6ib8qs73a.example"
   /* 4-2-1-6 doublediac2<0075><0301><0308><00ED>dn.example -> doublediac2<01D8><00ED>dn.example */
   /* Don't resolve as xn--doublediac2udn-cmb526fod.example */
  },
  {"\x6e\x65\x77\x6e\x6f\x72\x6d\xf0\xaf\xa1\xb4\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--newnormdn-m5a7856x.example", IDN2_DISALLOWED
   /* 4-2-2-1 newnorm<2F874><00ED>dn.example -> newnorm<5F33><00ED>dn.example should not become <5F53> */
   /* Don't resolve as xn--newnormdn-m5a9396x.example */
   /* Don't resolve as xn--newnormdn-m5a9968x.example */
   /* U+2f876 not IDNA2008-valid */
  },
  {"\xe2\x80\x80\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_NOT_NFC
   /* 4-3-1 Spacing */
   /* Don't resolve as xn--dn-mja3392a.example */
  },
  {" ídn.example", "", IDN2_DISALLOWED
   /* NFKC of previous.  U+0020 */
  },
  {"\xdb\x9d\xc3\xad\x64\x6e\x2d\x32\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-2 Control */
   /* Don't resolve as xn--dn-2-upa332g.example */
  },
  {"\xee\x80\x85\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-3 Private use */
   /* Don't resolve as xn--dn-mja1659t.example */
  },
  {"\xf3\xb0\x80\x85\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-4 Private use, non-BMP */
   /* Don't resolve as xn--dn-mja7922x.example */
  },
  {"\xef\xb7\x9d\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-5 Non-character */
   /* Don't resolve as xn--dn-mja1210x.example */
  },
  {"\xf0\x9f\xbf\xbe\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-6 Non-character, non-BMP */
   /* Don't resolve as xn--dn-mja7922x.example */
  },
  {"\xef\xbf\xbd\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-7 Surrogate points */
   /* Don't resolve as xn--dn-mja7922x.example */
  },
  {"\xef\xbf\xba\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-8 Inappropriate for plain */
   /* Don't resolve as xn--dn-mja5822x.example */
  },
  {"\xe2\xbf\xb5\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-9 Inappropriate for canonical */
   /* Don't resolve as xn--dn-mja3729b.example */
  },
  {"\xe2\x81\xaa\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-10 Change display simple */
   /* Don't resolve as xn--dn-mja7533a.example */
  },
  {"\xe2\x80\x8f\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-11 Change display RTL */
   /* Don't resolve as xn--dn-mja3992a.example */
  },
  {"\xf3\xa0\x80\x81\xf3\xa0\x81\x85\xf3\xa0\x81\x8e\x68\x69\x69\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_DISALLOWED
   /* 4-3-12 Language tags */
   /* Don't resolve as xn--hiidn-km43aaa.example */
  },
  {"\xd8\xa8\x6f\xd8\xb8\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_BIDI
   /* 4-4-1 Arabic RandALCat-LCat-RandALCat */
   /* Don't resolve as xn--o-0mc3c.example */
  },
  {"\xd8\xa8\xd8\xb8\x6f\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_BIDI
   /* 4-4-2 Arabic RandALCat-RandALCat-other */
   /* Don't resolve as xn--o-0mc2c.example */
  },
  {"\x6f\xd8\xa8\xd8\xb8\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_BIDI
   /* 4-4-3 Arabic other-RandALCat-RandALCat */
   /* Don't resolve as xn--o-1mc2c.example */
  },
  {"\xd7\x91\x6f\xd7\xa1\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_BIDI
   /* 4-4-4 Hebrew RandALCat-LCat-RandALCat */
   /* Don't resolve as xn--o-1hc3c.example */
  },
  {"\xd7\x91\xd7\xa1\x6f\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_BIDI
   /* 4-4-5 Hebrew RandALCat-RandALCat-other */
   /* Don't resolve as xn--o-1hc2c.example */
  },
  {"\x6f\xd7\x91\xd7\xa1\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "", IDN2_BIDI
   /* 4-4-6 Hebrew other-RandALCat-RandALCat */
   /* Don't resolve as xn--o-2hc2c.example */
  },
  {"\xc8\xb7\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--dn-mja33k.example"
   /* 5-1-1 Unassigned in BMP; zone editors should reject */
  },
  {"\xf0\x90\x88\x85\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--dn-mja7734x.example", IDN2_UNASSIGNED
   /* 5-1-2 Unassinged outside BMP; zone editors should reject */
   /* Don't resolve as xn--dn-mja7922x.example */
  },
  {"\xc8\xb4\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--dn-mja12k.example"
   /* 5-2-1 Newly assigned in BMP; zone editors should reject */
  },
  {"\xf0\x90\x80\x85\xc3\xad\x64\x6e\x2e\x65\x78\x61\x6d\x70\x6c\x65",
   "xn--dn-mja9232x.example"
   /* 5-2-2 Newly assigned outside of BMP; zone editors should reject */
   /* Don't resolve as xn--dn-mja7922x.example */
  }
};

int debug = 1;
int error_count = 0;
int break_on_error = 1;

void
fail (const char *format, ...)
{
  va_list arg_ptr;

  va_start (arg_ptr, format);
  vfprintf (stderr, format, arg_ptr);
  va_end (arg_ptr);
  error_count++;
  if (break_on_error)
    exit (EXIT_FAILURE);
}

void
hexprint (const char *str, size_t len)
{
  size_t i;

  printf ("\t;; ");
  if (str && len)
    for (i = 0; i < len; i++)
      {
	printf ("%02x ", (str[i] & 0xFF));
	if ((i + 1) % 8 == 0)
	  printf (" ");
	if ((i + 1) % 16 == 0 && i + 1 < len)
	  printf ("\n\t;; ");
      }
  printf ("\n");
}

int
main (void)
{
  uint8_t *out;
  size_t i;
  int rc;

  puts ("-----------------------------------------------------------"
	"-------------------------------------");
  puts ("                                          IDNA2008 Lookup\n");
  puts ("  #  Result                    ACE                         "
	"             Unicode input");
  puts ("-----------------------------------------------------------"
	"-------------------------------------");
  for (i = 0; i < sizeof (idna) / sizeof (idna[0]); i++)
    {
      rc = idn2_lookup_u8 (idna[i].in, &out, 0);
      printf ("%3d  %-25s %-40s %s\n", i, idn2_strerror_name (rc),
	      rc == IDN2_OK ? idna[i].out : "", idna[i].in);
      if (rc != idna[i].rc)
	fail ("expected rc %d got rc %d\n", idna[i].rc, rc);
      else if (rc == IDN2_OK && strcmp (out, idna[i].out) != 0)
	fail ("expected: %s\ngot: %s\n", idna[i].out, out);
    }

  return error_count;
}