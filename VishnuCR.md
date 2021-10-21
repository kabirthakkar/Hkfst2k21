
#include<stdio.h>
struct Employee
 {
   char Name[20];
   int Emp_id;
   float Salary;
  };
int main()
{
    struct Employee emp[20];
    int i,n;
    printf("Enter the no. of Employee: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      printf("Enter full name: ");
      scanf("%s",emp[i].Name);
      printf("Enter employee id: ");
      scanf("%d",&emp[i].Emp_id);
      printf("Enter salary: ");
      scanf("%f",&emp[i].Salary);
     }
     printf("Display Information\n");
     for(i=0;i<n;i++)
     {
      printf("Name: %s\n",emp[i].Name);
      printf("Employee Id:%d\n",emp[i].Emp_id);
      printf("Salary: %.2f\n",emp[i].Salary);
      }
  return 0;
 }
