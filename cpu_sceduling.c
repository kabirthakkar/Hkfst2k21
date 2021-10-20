#include <stdio.h>
#include <stdlib.h>
int ar[15],bur_tym[15],n,s1,s2;
float av1,av2;
struct pro{
    int name;
    int arr_tym;
    int bur_tym; 
    int wait;
    int turn;
    int compl;
    int pr;
    int re;
    int visited;
}p[10],te;
void dis(){
	int s1=0,s2=0;
    for(int i=0;i<n;i++){
        s1=s1+p[i].wait;
        s2=s2+p[i].turn;
    }
    av1=(float)s1/n;
    av2=(float)s2/n;
    printf("\nAverage waiting time : %.2f\n",av1);
    printf("Average Turnaround time : %.2f\n",av2);
}
void clear(){
    for(int i=0;i<n;i++)
    {
        p[i].turn=0;
        p[i].wait=0;
        p[i].visited=0;
        p[i].re=0;
    }
}
void sca1(){
    printf("Enter the number of processes\n");
    scanf("%i",&n);
    printf("Enter the Arrival time,Burst time and priority of each process\n");
    for (int i=0;i<n;i++){
        printf("\nP%i\n",i+1);
        p[i].name=i+1;
        scanf("%i %i %i",&p[i].arr_tym,&p[i].bur_tym,&p[i].pr);
    }
}
void sort(){
int min_idx;
for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (p[j].arr_tym < p[min_idx].arr_tym)
                min_idx = j;
        te=p[min_idx];
        p[min_idx]=p[i];
        p[i]=te;
    }
}
void fcfs(){
    sort();
    int compl;
    if(p[0].arr_tym>0){ 
        compl=p[0].arr_tym;
    }
    else{ 
        compl=0;
    }
    p[0].compl=compl+p[0].bur_tym;
    for(int i=1;i<n;i++)
    {
        if(p[i-1].compl>p[i].arr_tym){
            p[i].compl=p[i-1].compl+p[i].bur_tym;
        }
        else{
            p[i].compl=p[i].arr_tym+p[i].bur_tym;
        }
    }
    for(int i=0;i<n;i++){
        p[i].turn=p[i].compl-p[i].arr_tym;
        p[i].wait=p[i].turn-p[i].bur_tym;
    }
    for(int i=0;i<n;i++){
        printf("\nP%i %i %i %i %i %i\n",p[i].name,p[i].arr_tym,p[i].bur_tym,p[i].compl,p[i].wait,p[i].turn);
    }
    dis();
}
void sjf(){
    sort();
    int compl,i,mi,lp;
    if(p[0].arr_tym>0){ compl=p[0].arr_tym;}else{ compl=0;}
    lp=0;
    mi=0;
    for(int i=1;i<n;i++)
    {
        if(p[mi].bur_tym>p[i].bur_tym && p[mi].arr_tym==p[i].arr_tym)
        {
            mi=i;
        }
    }
    p[mi].compl=p[mi].bur_tym;
    p[mi].visited=1;
    lp=mi;
    int cou=0,j;
    cou=p[lp].compl;
    for( i=0;i<n ;){
        if(p[i].visited!=1){
            if(cou>p[i].arr_tym){
                mi=i;
                j=i+1;
                while(j<n && p[j].arr_tym<=p[lp].compl){  
                    if(p[mi].bur_tym>p[j].bur_tym &&p[j].visited!=1)
                    {
                        mi=j;
                    }
                    j++;
        
                }
                if(mi==i)
                {
                    p[i].compl=p[lp].compl+p[i].bur_tym;
                    cou=p[i].compl;
                    p[i].visited=1;
                    lp=i;
                    i++;    
                }
                else{
                    p[mi].visited=1;
                    p[mi].compl=p[lp].compl+p[mi].bur_tym;
                    lp=mi;
                    cou=p[mi].compl;
                }
            }
            else{
                cou++;
            }
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
        p[i].turn=p[i].compl-p[i].arr_tym;
        p[i].wait=p[i].turn-p[i].bur_tym;
    }
    for(int i=0;i<n;i++){
        printf("\nP%i %i %i %i %i %i\n",p[i].name,p[i].arr_tym,p[i].bur_tym,p[i].compl,p[i].wait,p[i].turn);
    }
    dis();
}

void priority(){
    sort();
    int compl,i,mi,lp;
    if(p[0].arr_tym>0){ 
        compl=p[0].arr_tym;
    }
    else{ 
        compl=0;
    }
    lp=0;
    mi=0;
    for(int i=1;i<n;i++)
    {
        if(p[mi].pr>p[i].pr && p[mi].arr_tym==p[i].arr_tym)
        {
            mi=i;
        }
    }
    p[mi].compl=p[mi].bur_tym;
    p[mi].visited=1;
    lp=mi;
    int cou=0,j;
    cou=p[lp].compl;
    for( i=0;i<n ;){
        if(p[i].visited!=1){
            if(cou>p[i].arr_tym){
                mi=i;
                j=i+1;
                while(j<n && p[j].arr_tym<=p[lp].compl){  
                    if(p[mi].pr>p[j].pr && p[j].visited!=1)
                    {
                        mi=j;
                    }
                    j++;
                }
                if(mi==i)
                {
                    p[i].compl=p[lp].compl+p[i].bur_tym;
                    cou=p[i].compl;
                    p[i].visited=1;
                    lp=i;
                    i++;   
                }
                else{
                    p[mi].visited=1;
                    p[mi].compl=p[lp].compl+p[mi].bur_tym;
                    lp=mi;
                    cou=p[mi].compl;
                }
            }
            else{
                cou++;
            }
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
        p[i].turn=p[i].compl-p[i].arr_tym;
        p[i].wait=p[i].turn-p[i].bur_tym;
    }
    for(int i=0;i<n;i++){
        printf("\nP%i %i %i %i %i %i\n",p[i].name,p[i].arr_tym,p[i].bur_tym,p[i].compl,p[i].wait,p[i].turn);
    }
    dis();
}
void rb(){
    int q;
    printf("Enter time quantum\n");
    scanf("%i",&q);
    sort();
    for(int i=0;i<n;i++){
        p[i].re=p[i].bur_tym;
    }
    int y=0,c=0;
    int compl=p[0].arr_tym,i;
    int re[100],fi=0,va=1;
    re[0]=0;
    while(y==0)
    {
        int h=re[fi];
        if(p[h].re!=0)
        {
            if(p[h].re>q){
                p[h].re-=q;
                compl+=q;
                }
                else{
                compl+=p[h].re;
                p[h].compl=compl;
                p[h].re=0;
            }
        }
        fi++;
        for(i=0;i<n;i++){
            if(p[i].visited!=1)
            {
                if(h==i)
                {
                    continue;
                }
                else{
                    if(compl>=p[i].arr_tym)
                    {
                        p[i].visited=1;
                        re[va]=i;
                        va++;
                    }
                }
            }
        }
        if(p[h].re!=0)
        {
            p[h].visited=1;
            re[va]=h;
            va++;
        }
        c=0;
        for(i=0;i<n;i=(i+1)){
            if(p[i].re==0){
                c++;
            }
        }
        if(c==n)
        {
            y=1;
        }
        if(fi==va){
            for(i=0;i<n;i++){
                if(compl<=p[i].arr_tym && p[i].visited!=1)
                {
                    compl=p[i].arr_tym;
                    p[i].visited=1;
                    re[va]=i;
                    va++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        p[i].turn=p[i].compl-p[i].arr_tym;
        p[i].wait=p[i].turn-p[i].bur_tym;
    }
    for(int i=0;i<n;i++){
        printf("\nP%i %i %i %i %i %i\n",p[i].name,p[i].arr_tym,p[i].bur_tym,p[i].compl,p[i].wait,p[i].turn);
    }
    dis();
  
}
void main(){
    int i;
    sca1();
    while(1){ 
        printf("\n1. FCFS\n2. SJF\n3. Priority\n4. Round robin\n5. Exit\n");
        printf("Enter your choice\n");
        scanf("%i",&i);
        switch(i){
        case 1:
            fcfs(); 
            clear();	
            break;
        case 2:
            sjf();
            clear();
            break;
        case 3:priority();
            clear();
            break;
        case 4:rb();
            clear();
            break;
        case 5:exit(0);
        default:printf("Entter correct option");
        }
    }
}
