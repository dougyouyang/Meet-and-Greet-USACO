/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/

#include <iostream>

using namespace std;
int move1[1000005], move2[1000005], s=0, s2=0;

int main()
{
    char di;
    int b, e, bb, ee, pb=1000000000, pe=1000000000, sum=0;
    int i, j;
    
    cin >> b >> e;
    for(i=0;i<b;i++){
        cin >> bb >> di;
        if(di=='L'){
            for(j=0;j<bb;j++){
                move1[s++]=1;
            }
        }
        else{
            for(j=0;j<bb;j++){
                s++;
            }
        }
    }
    for(i=0;i<e;i++){
        cin >> ee >> di;
        if(di=='L'){
            for(j=0;j<ee;j++){
                move2[s2++]=1;
            }
        }
        else{
            for(j=0;j<ee;j++){
                s2++;
            }
        }
    }
    
    for(i=0;i<10000000;i++){
        if(i>s && i>s2)
            break;
        if(move1[i]==1 && i<s){
            pb--;
        }
        else if(move1[i]==0 && i<s){
            pb++;
        }
        if(move2[i]==1 && i<s2){
            pe--;
        }
        else if(move2[i]==0 && i<s2){
            pe++;
        }
        if(pb==pe){
            if(i<s && i<s2 && move1[i]!=move2[i]){
                sum++;
            }
            else if(i>=s || i>=s2){
                sum++;
            }
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
