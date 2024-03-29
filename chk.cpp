#include <iostream>
#include <string>
#include <chrono>
using namespace std;

void getLocalUTCTime(string &time, string &code) {
  auto now = chrono::system_clock::now();
  auto now_utc = chrono::system_clock::to_time_t(now);
  struct tm tm_utc;
  gmtime_s(&tm_utc, &now_utc);
  int year = tm_utc.tm_year + 1900;
  int month = tm_utc.tm_mon + 1;
  int day = tm_utc.tm_mday;
  int hour = tm_utc.tm_hour;
  int minute = tm_utc.tm_min;
  int sum = year + month + day + hour + minute;
  int pre_sum = year + month + day + hour + minute;
  int otp = sum ^ 64 % 10000;
  int pre_otp = pre_sum ^ 64 % 10000;
  time = to_string(year) + "-" + to_string(month) + "-" + to_string(day) + "-" + to_string(hour) + "-" + to_string(minute);
  code = to_string(otp);
}

int main() {
  string time, code;
  getLocalUTCTime(time, code);
  cout << "local utc = " << time << endl;
  //cout << "local otp = " << code << endl;
  cout << "plz enter otp: " << endl;
  string input;
  cin >> input;
  if (input == code) {
    cout << "success" << endl;
  } else if (input == pre_code) {
    cout << "success" << endl;
  } else {
    cout << "fail" << endl;
  }
  return 0;
}
