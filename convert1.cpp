#include <iostream>
#include <string>

using namespace std;

string one[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string ten[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string convertToWords(int num) {
    if (num < 20) {
        return one[num];
    } else if (num < 100) {
        return ten[num / 10] + (num % 10 != 0 ? " " + one[num % 10] : "");
    } else if (num < 1000) {
        return one[num / 100] + " Hundred" + (num % 100 != 0 ? " and " + convertToWords(num % 100) : "");
    } else if (num < 1000000) {
        return convertToWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + convertToWords(num % 1000) : "");
    } else if (num < 10000000) {
        return convertToWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + convertToWords(num % 1000000) : "");
    } else {
        return "Number is too large to convert";
    }
}

int main() {
    int N;
    cout << "Enter an integer: ";
    if (cin >> N) {
        cout << "Output: " << convertToWords(N) << endl;
    } else {
        cout << "Input is not an integer" << endl;
    } 
    return 0;
}