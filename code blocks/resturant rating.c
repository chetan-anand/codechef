#include<stdio.h>
void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;

  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
}
int main()
{
    int n,o,x[25001],cnt=0,temp=0,ans,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&o);
        if(o==1)
        {
            scanf("%d",&x[cnt]);
            cnt++;
        }
        else
        {
            if(cnt<3){printf("No reviews yet\n");}
            else
            {
                q_sort(x,temp,cnt-1);
                printf("%d\n",x[cnt-cnt/3]);
                temp=cnt-cnt/3;
            }
        }
    }
    return 0;
}
