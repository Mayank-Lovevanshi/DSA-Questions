int main()
{
int low = 0;

**********
* Part -I*
*******************************
*for(int high=0;high<n;high++)*
*{			      *
*information+=a[high];        *
*******************************

***********
* Part -II*
*******************************
while(information->sahi)      *
{      		              *
ans = min(ans,high-low+1);    *
information-=a[low];   	      *
low++;			      *
} 			      *
*******************************
}
}
