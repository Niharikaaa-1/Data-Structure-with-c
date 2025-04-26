int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time=0;
    while(tickets[k]!=0){
        for(int i=0;i<ticketsSize;i++){
            if(tickets[i]!=0){
                tickets[i]-=1;
                time++;
            }
            if(tickets[k]==0)
                break;
        }
    }
    return time;
}
