int* solve(int arr_count, int* arr, int queries_count, int* queries) {
    int *ans=(int *)(malloc(queries_count*(sizeof(int))));
    int ans_count=0;
    for(int i=0;i<queries_count;i++)
    {
        int stack1[queries[i]];
        int top1=0;
        int stack2[queries[i]];
        int top2=0;
        for(int j=queries[i]-1;j>=0;j=j-1)
        {
            if(top2>0)
            {
                if(stack2[top2-1]<arr[j])
                    stack2[top2]=arr[j];
                else
                    stack2[top2]=stack2[top2-1];
            }
            else
                stack2[top2]=arr[j];
            top2++;
        }
        int min=stack2[top2-1];
        int q=queries[i];
        while(q<arr_count)
        {
            if(top2>0)
            {
                top2=top2-1;
            }
            else
            {
                for(int j=q-1;j>=q-queries[i];j=j-1)
                {
                    if(top2>0)
                    {
                        if(stack2[top2-1]<arr[j])
                            stack2[top2]=arr[j];
                        else
                            stack2[top2]=stack2[top2-1];
                    }
                    else
                        stack2[top2]=arr[j];
                    top2++;
                    top1=0;
                }
                top2=top2-1;
            }
            if(top1>0)
            {
                if(stack1[top1-1]<arr[q])
                    stack1[top1]=arr[q];
                else
                    stack1[top1]=stack1[top1-1];
            }
            else
                stack1[top1]=arr[q];
            top1++;
            int max=stack1[top1-1];
            if(top2>0)
                if(max<stack2[top2-1])
                    max=stack2[top2-1];
            if(min>max)
            min=max;
            q++;
        }
        ans[ans_count]=min;
        ans_count++;
    }
    return ans;

}
