/*
    จงเขียนโปรแกรมเพื่อรับคำจากผู้ใช้งาน เพื่อตรวจสอบว่า คำที่กรอกมามีลักษณะเป็นคำหรือวลีที่สามารถอ่านจากหลังไปหน้าหรือหน้าไปหลังแล้วยังคงความหมายเหมือนเดิมได้
    โดยที่ หากคำนั้นสามารถอ่านจากหน้าไปหลังหรือหลังไปได้ ให้แสดงผลลัพธ์ว่า Pass แต่หากทำไม่ได้ให้ขึ้นว่า Not Pass

    Test case:
        Enter word:
            radar
    Output:
        Pass.

    Test case:
        Enter word:
            hello
    Output:
        Not Pass.

    Test case:
        Enter word:
            Radar
    Output:
        Pass.

    Test case:
        Enter word:
            here
    Output:
        Not Pass.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ฟังก์ชันสำหรับตรวจสอบว่าคำนั้นสามารถอ่านจากหน้าไปหลังหรือหลังไปหน้าได้หรือไม่
int isPalindrome(char *word) {
    int left = 0;
    int right = strlen(word) - 1;

    while (left < right) {
        // ไม่สนใจตัวอักษรที่ไม่ใช่ตัวอักษรตัวพิมพ์ใหญ่หรือตัวเล็ก
        while (!isalpha(word[left]) && left < right) {
            left++;
        }
        while (!isalpha(word[right]) && left < right) {
            right--;
        }

        // เปรียบเทียบตัวอักษรที่อ่านจากหน้าไปหลัง
        if (tolower(word[left]) != tolower(word[right])) {
            return 0; // ไม่ Pass
        }

        left++;
        right--;
    }

    return 1; // Pass
}

int main() {
    char word[100];

    printf("Enter word: ");
    scanf("%s", word);

    if (isPalindrome(word)) {
        printf("Pass.\n");
    } else {
        printf("Not Pass.\n");
    }

    return 0;
}
//end main function