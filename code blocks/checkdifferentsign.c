#include <stdio.h>
int apposite(int x,int y){
    return((x^y)<0);

}
int main() {
    int x=100;
    int y=-100;
    if(apposite(x,y)==1)printf("Differ Sign");
    else{
        printf("same sign");

    }
    return 0;
}
