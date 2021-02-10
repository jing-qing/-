int maxProfit(int* prices, int pricesSize)
{
    int i,w=0;

    for(i=0;i<pricesSize-1;i++)
    {
        if(prices[i]<prices[i+1])
        {
            w=w+prices[i+1]-prices[i];
        }       
        else
        w=w+0; 
    }

    return w;
}