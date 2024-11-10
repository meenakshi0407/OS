
#include <iostream>
using namespace std;

int main()
{
    int pages[30],n,frames,temp[10],pagefound,emptyslot,pos=0,fault=0;
    
    cout <<"Enter no. of pages\n";
    cin>>n;

    cout<<"Enter reference string \n";
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    cout<<"Enter no. of frames\n";
    cin>>frames;
    
    for(int i=0;i<frames;i++){
        temp[i]=-1;
    }
    for(int i=0;i<n;i++){
        pagefound=0;
        
        for(int j=0;j<frames;j++){
            if(temp[j]==pages[i]){
                pagefound=1;
                break;
            }
        }
        if(pagefound==0){
            emptyslot=0;
            for(int j=0;j<frames;j++){
                if(temp[j]==-1){
                    fault++;
                    temp[j]=pages[i];
                    emptyslot=1;
                    break;
                }
            }
        
        if(emptyslot==0){
            temp[pos]=pages[i];
            pos++;
            if(pos>=frames){
                pos=0;
            }
            fault++;
        }
    }
        cout<<"\n";
        for(int j=0;j<frames;j++){
            cout<<temp[j]<<" ";
        }
    }
        cout<<"\n";
        cout<<"Page faults are :"<<fault;

    return 0;
}