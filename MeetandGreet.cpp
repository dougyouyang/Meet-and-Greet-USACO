//  Copyright © 2017 Dougy Ouyang. All rights reserved.

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
