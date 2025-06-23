#include <stdio.h>

float to_fahrenheit(float c){
    return (c * 9/5) + 32;
}

float to_celcius(float f){
    return (f-32)*5/9;
}

int main(){
    float t, x;
    char value, converted_value;
    printf("Enter F for converting to Celcius or C for converting to Fahrenheit: ");
    scanf("%c", &value);
    printf("Enter the degree to convert: " );
    scanf("%f", &x);

    if (value =='F' || value == 'f'){
        converted_value = 'C';
    }
    else{
        converted_value = 'F';
    }
    if (value =='F' || value == 'f'){
        t = to_celcius(x);
    }
    else if (value =='C' || value == 'c'){
        t = to_fahrenheit(x);
    }
    else{
        printf("Enter the correct value for converting i.e 'C' or 'F' ");
    }
    printf("The value of %.2f degree %c is %.2f degree %c.\n", x, value, t, converted_value);

    return 0;
}