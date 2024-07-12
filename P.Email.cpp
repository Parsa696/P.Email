#include <iostream>
#include <string>

using namespace std;

// ساختار برای ذخیره ایمیل
struct Email {
    string address;
};

// تابع اعتبارسنجی ایمیل
bool isValidEmail(const string& email) {
    // پیدا کردن محل '@'
    size_t atPos = email.find('@');
    if (atPos == string::npos) {
        return false; // اگر '@' پیدا نشد
    }

    // پیدا کردن محل '.'
    size_t dotPos = email.find('.', atPos);
    if (dotPos == string::npos) {
        return false; // اگر '.' بعد از '@' پیدا نشد
    }

    // بررسی اینکه '@' و '.' در مکان مناسب باشند
    if (atPos < 1 || dotPos < atPos + 2 || dotPos + 2 >= email.length()) {
        return false;
    }

    return true;
}

int main() {
    Email userEmail;

    cout << "لطفاً ایمیل خود را وارد کنید: ";
    cin >> userEmail.address;

    if (isValidEmail(userEmail.address)) {
        cout << "ایمیل معتبر است." << endl;
    } else {
        cout << "ایمیل نامعتبر است." << endl;
    }

    return 0;
}
