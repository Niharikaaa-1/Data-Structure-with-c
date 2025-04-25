int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int stack=(int)malloc(sizeof(int) * asteroidsSize);
    int top=-1;
    for(int i=0;i<asteroidsSize;i++){
        int flag=0;
        while(top>=0  && stack[top]>0 && asteroids[i]<0){
            if(stack[top]==-asteroids[i]){
                top--;
                flag=1;
                break;
            }
            else if(stack[top]>-asteroids[i]){
                flag=1;
                break;
            }
            else {
                top--;
            }
        }
        if(flag==0)
        stack[++top]=asteroids[i];
    }
    *returnSize=top+1; 
    return stack;
}
