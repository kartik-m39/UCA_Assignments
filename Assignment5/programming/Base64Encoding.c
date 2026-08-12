#include <stdio.h>

const char b64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* Base64Encode(char input[], int n){

    static char output[100] = "";
    
    int pads = (n % 3 == 0) ? 0 : 3 - (n % 3);   // number of '=' to add, as if 1 then add 2 and vice versa
    int idx = 0;              // for output array

    idx = 0;                // Reseting index counter explicitly
    for(int i = 0; i < 100; i++) output[i] = '\0';      // Clearing the old garbage data

    int combined = 0;
    
    for(int i = n-1 ; i >= 0; i--){
        // placing each ascii (in binary form) at its correct octet
        // input[n-i-1] gives the char which is under the hood ascii thus in turn in binary 
        // shifting it by multiple of 8 places it at right location
        // Doing a OR combines all the bytes of different chars together

        combined |= input[n-i-1] << (8 * i);
    }

    combined <<= pads * 8; // adding the 0 bits to make it a 24 bit block

    // Splitting into 6 bits group
    // Right shift by 6*i will give the 6bits and 
    // Doing & with 0x3F (0011 1111) will add padding in front if required
    
    for(int i = 3; i >= 0; i--){

        int base64_val = combined >> (6*i) & 0x3F; 
        output[idx++] = b64_table[base64_val];
    }


    // for(int i = 0; i < 10; i++){
    //     printf("%c", output[i]);
    // }

    if (pads == 2) {
        output[idx - 1] = '=';
        output[idx - 2] = '=';
    } else if (pads == 1){
        output[idx - 1] = '=';
    }
    output[idx] = '\0';

    return output;
}

int main(){

    char input[] = "Man";
    char input2[] = "Ma";
    
    char* output = Base64Encode(input, 3);
    printf("%s\n", output);

    char* output2 = Base64Encode(input2, 2);
    printf("%s\n", output2);

    return 0;
}
