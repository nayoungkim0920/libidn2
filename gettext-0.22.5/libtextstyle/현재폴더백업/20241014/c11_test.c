#include <iostream>
#include <string_view>  // C++17에서 추가된 std::string_view 사용

int main() {
    // C++17에서 추가된 static_assert로 지원 여부를 확인합니다.
    static_assert(true, "C++17 is supported.");

    // C++17에서 추가된 std::string_view 사용
    std::string_view message = "C++17 is supported.";

    // 메시지를 출력
    std::cout << message << std::endl;

    return 0;
}
