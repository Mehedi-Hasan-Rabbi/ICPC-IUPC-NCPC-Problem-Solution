#include <stdio.h>
int main()
{
    int t,k,i,j=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        long long int ara[k];
        for(i=0; i<k; i++)
        {
            scanf("%lld",&ara[i]);
        }
        int temp;
        for(i=0; i<k; i++)
        {
            if(ara[i] > ara[i+1])
            {
                temp=ara[i+1];
                ara[i+1]=ara[i];
                ara[i]=temp;
            }
        }
        if(k==1 && (ara[0]* ara[0])!=1)
        {
            printf("Case %d: %lld\n",j,ara[0] * ara[0]);
        }
        else if((ara[0] * ara[k-1])!=1)
        {
            printf("Case %d: %lld\n",j,ara[0] * ara[k-1]);
        }
        j++;
    }
    return 0;
}
