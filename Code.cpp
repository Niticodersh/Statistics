#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//#include "Minor 1 Marks - Sheet1.csv"
int partition(float*arr,int low,int high)
{
    float pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {  
            i++;
            float temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    float temp=arr[i];
    arr[i]=arr[high];
    arr[high]=temp;
    return i;
}
void quicksort(float *arr,int low,int high)
{
    if(low < high)
    {
        int pivot_index=partition(arr,low,high);
        quicksort(arr,low,pivot_index-1);
        quicksort(arr,pivot_index+1,high);
    }
}
int main()
{
    float marks[1000];
    string myFilePath="Minor 1 Marks - Sheet1.csv";
    ifstream allStudents;
    allStudents.open(myFilePath);
    if(allStudents.fail())
    {
        cerr<<"Unable to open file"<<myFilePath<<endl;
        return 1;
    }
    int NoOfEntries=0;
    string records;
    while(allStudents.peek()!=EOF)
    {
        getline(allStudents,records,' ');
    }
    string input="";
    for(auto x:records)
    {
        if(x=='\n' || x==' ')
        {
            marks[NoOfEntries++]=stof(input);
            input="";
        }
        else
        {
            input=input+(x);
        }
    }
    marks[NoOfEntries++]=stof(input);
    int max=0;
    for(int i=0;i<NoOfEntries;i++)
    {
        if(marks[i]>max)
        {
            max=marks[i];
        }
    }    
    float sum=0;
    //Q1. Mean , Median and Mode
    //Mean
    for(int i=0;i<NoOfEntries;i++)
    {
        sum=sum+marks[i];
    }
    float mean;
    mean=(sum/NoOfEntries);
    cout<<endl<<endl;
    cout<<"Mean of the class : "<<mean<<endl;
    //Median
    //First sort the records
    quicksort(marks,0,NoOfEntries-1);
    if(NoOfEntries%2==0)
    {
        cout<<"Median of the class : "<<((marks[NoOfEntries/2]+marks[(NoOfEntries-1)/2])/2);
    }
    else
    {
        cout<<"Median of the class : "<<marks[NoOfEntries/2];
    }
    cout<<endl;
    //Mode
    float distinct_elemnets[NoOfEntries];
    float occur[NoOfEntries];
    float temp=-1;
    int index=-1;
    for(int i=0;i<NoOfEntries;i++)
    {
        if(temp!=marks[i])
        {
            index=index+1;
            temp=marks[i];
            distinct_elemnets[index]=marks[i];
            occur[index]=1;
        }
        else
        {
            occur[index]=occur[index]+1;
        }
    } 
    int max_count=0;
    for(int i=0;i<=index;i++)
    {
        if(occur[i]>max_count)
        {
            max_count=occur[i];
        }
    }
    cout<<"Mode of the Class : ";
    for(int i=0;i<=index;i++)
    {
        if(occur[i]==max_count)
        {
            cout<<distinct_elemnets[i]<<" ";
        }
    }
    // Variance
    float mean_square_diff_Sum=0;
    for(int i=0;i<NoOfEntries;i++)
    {
            mean_square_diff_Sum=mean_square_diff_Sum+((marks[i]-mean)*(marks[i]-mean));
    }
    float var;
    float sample_var;
    var=mean_square_diff_Sum/NoOfEntries;
    sample_var=mean_square_diff_Sum/(NoOfEntries-1);
    cout<<endl;
    cout<<"Variance of the Class : "<<var;
    cout<<endl;
    cout<<"Sample Variance : "<<sample_var;
    cout<<endl<<endl;    
    cout<<"Histogram"<<endl<<endl;     
    cout<<"Y-Axis -> No. of Students"<<endl<<endl;
    cout<<"X-Axis -> Marks of Students"<<endl<<endl;
    cout<<"X AXIS Bin / class range : 0.5 marks"<<endl<<endl;
    cout<<"Y - AXIS 1 unit = 1 Student"<<endl<<endl;
    int maxElement=0;
    for(int i=0;i<=index;i++)
    {
        if(occur[i]>maxElement)
        {
            maxElement=occur[i];
        }
    }
    for(int i=maxElement;i>=0;i--)
    {
        cout.width(5);
        cout<<right<<i<<"|";
        for(int j=0;j<=index;j++)
        {
            if(occur[j]>=i)
            {
                cout<<"xxx ";
            }
            else
            {
                cout<<"    ";
            }
        }
        cout<<endl;
    }
    cout<<"      ";
    for(int i=0;i<index;i++)
    {
        cout<<"----";
    }
    cout<<"--";
    cout<<endl;
    cout<<"      ";
    cout<<"0  0.5  1  1.5  2  2.5  3  3.5 4  4.5  5  5.5  6  6.5  7  7.5  8  8.5  9  9.5  10 10.5 11 11.5 12 12.5 13 13.5 14 14.5 15  15.5";
    cout<<endl<<"                                              Marks of Students ------->                                             ";
    cout<<endl<<"Owner : Nitish Bhardwaj (B21AI056)"<<endl<<endl<<endl;
    return 0;
}