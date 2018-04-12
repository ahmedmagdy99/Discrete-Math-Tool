// FCI – Programming 1 – 2018 - Assignment 3
// Program Name:Discrete Math Tools
// Last Modification Date: 05/04/2018
// Author1 and ID and Group:ahmed magdy mohamed 20170027 G2
// Author2 and ID and Group:ahmed mostafa elsayed 20170033 G2
// Author3 and ID and Group:ahmed gomaa 20170014 G1
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........
#include<bits/stdc++.h>
using namespace std;
int siz1, siz2, sizOf1, sizOf2;
int set1[5000];
int set2[5000];
void prepareSet(int& sizOf1, int& sizOf2);
void LoadData();
void EnterData();
void DisplayData();
void check_disjoint(int sizOf1, int sizOf2);
void check_equal(int sizOf1, int sizOf2);
void Union (int sizOf1, int sizOf2);
void intersection (int sizOf1, int sizOf2);
void A_B (int sizOf1, int sizOf2);
void check_proper(int sizOf1, int sizOf2);
void power_set(int sizOf1);
void power_set2(int sizOf2);
void diffrence(int sizOf1, int sizOf2);
void cartesian_product(int sizOf1, int sizOf2);
int main()
{
    bool isContinue=true, flag=true ;
    int need=0, sizeOfset1=0,powr=0;
    cout << "Ahlan ya user ya habibi :D" << endl;
    cout << "What do you like to do today ? " << endl;
loop3 :
    cout << endl;
    cout << "\n1- Enter a new data set" << endl;
    cout << "2- Load two data sets" << endl;
    cout << "3- Display data sets" << endl;
    cout << "4- Union of A,B" << endl;
    cout << "5- Intersection of A,B" << endl;
    cout << "6- A-B" << endl;
    cout << "7- B-A" << endl;
    cout << "8- Cartesian product of A and B" << endl;
    cout << "9- Power set of A" << endl;
    cout << "10- Check if A and B are disjoint" << endl;
    cout << "11- Check if A and B are equal" << endl;
    cout << "12- Check if a set is a proper subset of other" << endl;
    cout << "13- End" << endl;
    cout << "Enter Your Choice: ";
    cin >> need;
    while (isContinue)
    {
        if (need==1)
        {
            EnterData();
            prepareSet(sizOf1, sizOf2) ;
            goto loop3;
        }
        else if (need==2)
        {
            LoadData();
            prepareSet(sizOf1, sizOf2);
            goto loop3;
        }
        else if(need==3)
        {
            DisplayData();
            goto loop3;
        }
        else if(need==4)
        {
            Union(sizOf1, sizOf2);
            goto loop3;
        }
        else if (need==5)
        {
            intersection(sizOf1, sizOf2);
            goto loop3;
        }
        else if (need==6)
        {
            A_B(sizOf1, sizOf2);
            goto loop3;
        }
        else if (need==7)
        {
            for(int i=0; i<sizOf1; ++i)
            {
                cout << set1[i] << " ";
            }

            cout << endl;

            for(int j =0; j<sizOf2; ++j)
            {
                cout << set2[j] << " ";

            }
            cout<< endl;
            cout << "The complement is :" << endl;
            diffrence(sizOf1,sizOf2);
            goto loop3;
        }
        else if (need==8)
        {
            cartesian_product(sizOf1, sizOf2);
            goto loop3;
        }
        else if (need==9)
        {
            cout<< "if you want power set of A press 1 power set of B press 2: ";
            cin >> powr;
            if(powr==1){
                power_set(sizOf1);
            }
            else if(powr==2){
                power_set2(sizOf2);
            }
            goto loop3;
        }
        else if (need==10)
        {
            check_disjoint(sizOf1, sizOf2);
            goto loop3;
        }
        else if (need==11)
        {
            check_equal(sizOf1, sizOf2);
            goto loop3;
        }
        else if (need==12)
        {
            check_proper(sizOf1, sizOf2);
            goto loop3;
        }
        else if (need==13)
        {
            return 0;
        }
        else
        {
            cout<<endl<<"Please enter a valid number.."<<endl;
            goto loop3;
        }


        return 0 ;
    }

}

void prepareSet(int& sizOf1, int& sizOf2)
{
    int freq [100000] = {0}, c = 0 ;
    for (int i = 0 ; i<siz1 ; ++i)
        ++freq[set1[i]]  ;
    memset(set1,0,5000) ;
    for (int i = 0 ; i<100000 ; ++i)
    {
        if (freq[i]) set1[c++] = i ;
    }
    memset(freq,0,100000) ;
    for (int i = 0 ; i<siz2 ; ++i)
        ++freq[set2[i]]  ;
    memset(set2,0,5000) ;
    sizOf1 = c ;
    c = 0 ;
    for (int i = 0 ; i<100000 ; ++i)
    {
        if (freq[i]) set2[c++] =i;
    }
    sizOf2 = c ;
}

void EnterData ()
{
    int x=0,f=0,p=0;
    bool flag=true, flag3=true;
    char need3;
    char ItsName [100];
    char ItsName2 [100];
    char ItsName3 [100];
    cout << "write the name of file you want to create : ";
    cin >> ItsName;
    ofstream outfile(ItsName);
    int i=0;
    while(flag3)
    {
        cout<<"how many number you want to enter? : ";
        cin>>x;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "invalid"<<endl;
        }
        else
        {
            break;
            flag3=false;
        }
    }
    for (int c=0 ; c<x ; c++)
    {
        cout<<"number: ";
        while(flag)
        {
            cin >> set1[i];
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "invalid"<<endl;
            }
            else
            {
                outfile << set1[i] << "\n";
                i++;
                break;
            }
        }
    }
    siz1 = i;
    flag=false;

    cout << "write the name of the second file you want to create : ";
    cin >> ItsName2;
    ofstream outfile2(ItsName2);
    i=0;
    flag=true;
    flag3=true;
    while(flag3)
    {
        cout<<"how many number you want to enter? : ";
        cin>>f;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "invalid";
        }
        else
        {
            break;
            flag3=false;
        }
    }
    for (int t=0 ; t<f ; t++)
    {
        cout<<"number: ";
        while(flag)
        {
            cin >> set2[i];
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "invalid";
            }
            else
            {
                outfile2 << set2[i] << "\n";
                i++;
                break;
            }
        }
    }
    siz2 = i;
    flag=false;
    cout << "The Two Sets Are Ready"<<endl;
}

void LoadData ( )
{
    char name1[500];
    char name2[500];
    char name3[500];

loop1 :
    cout << "enter first file name : ";
    cin >> name1;
    ifstream file1 ;
    file1.open(name1) ;
    int x=0, sizeOfset=0;
    if (file1)
    {
        while(!file1.eof())
        {
            file1 >> set1[x];
            x++;
            sizeOfset++;
        }

    }
    else
    {
        cout << "Error in opening the file!!"<<endl;
        goto loop1;
    }
    siz1 = sizeOfset ;
    x=0,sizeOfset=0;
loop2 :
    cout << "enter second file name : ";
    cin >> name2;
    ifstream file2;
    file2.open(name2) ;
    if (file2)
    {
        while(!file2.eof())
        {
            file2 >> set2[x];
            x++;
            sizeOfset++;
        }

    }
    else
    {
        cout << "Error in opening the file!!"<<endl;
        goto loop2;
    }
    siz2 = sizeOfset;
    cout << "The Two Files Loaded"<<endl;
}


void DisplayData ()
{

    cout <<"-----------------------------"<<endl;
    cout << "setA = ";
    cout << "{";
    for (int i=0 ; i<sizOf1 ; i++)
    {
        if(set1[i]==set1[sizOf1-1])
        {
            cout << set1[i];
        }
        else
        {
            cout << set1[i] << ",";
        }
    }
    cout<<"}";
    cout << "\nsetB = ";
    cout << "{";
    for (int j=0 ; j<sizOf2 ; j++)
    {
        if(set2[j]==set2[sizOf2-1])
        {
            cout << set2[j];
        }
        else
        {
            cout << set2[j] << ",";
        }
    }
    cout << "}" << endl ;
    cout<<"-----------------------------"<<endl;

}
void check_disjoint(int sizOf1, int sizOf2)
{
    int counter=0;
    for (int i=0 ; i<sizOf1 ; i++)
    {
        for(int j=0 ; j<sizOf2 ; j++)
        {
            if (set1[i]==set2[j])
            {
                counter++;
            }
        }
    }
    if (counter>0)
    {
        cout <<"-----------------------------";
        cout << "\nThe two sets are not disjoint" << endl;
        cout <<"-----------------------------"<<endl;
    }
    else
    {
        cout <<"-----------------------------";
        cout << "\nThe two sets are disjoint" << endl;
        cout <<"-----------------------------"<<endl;
    }
}
void check_equal(int sizOf1, int sizOf2)
{
    int counter=0;
    for (int i=0 ; i<sizOf1 ; i++)
    {
        for(int j=0 ; j<sizOf2 ; j++)
        {
            if (set1[i]==set2[j])
            {
                counter++;
            }
        }
    }
    if(counter==sizOf1 & counter==sizOf2)
    {
        cout <<"-----------------------------";
        cout << "\nThe two sets are equal" << endl;
        cout <<"-----------------------------"<<endl;
    }
    else
    {
        cout <<"-----------------------------";
        cout << "\nThe two sets are not equal" << endl;
        cout <<"-----------------------------"<<endl;
    }
}
void check_proper(int sizOf1, int sizOf2)
{
    int p = true ;
    int counter=0;
    for(int i=0 ; i<sizOf1 ; i++)
    {
        for(int j=0 ; j<sizOf2 ; j++)
        {
            if(set1[i]==set2[j])
            {
                counter++;
            }
        }
    }

    if(sizOf1!=sizOf2 && counter==sizOf1)
    {
        p=false;
        cout <<"-----------------------------"<<endl;
        cout << "set A is proper subset of setB "<<endl;
        cout <<"-----------------------------"<<endl;
    }
    else
    {
        counter=0;
        for(int i=0 ; i<sizOf2 ; i++)
        {
            for(int j=0 ; j<sizOf1 ; j++)
            {
                if(set2[i]==set1[j])
                {
                    counter++;
                }
            }
        }

        if(sizOf1!=sizOf2 && counter==sizOf2)
        {
            p=false;
            cout <<"-----------------------------"<<endl;
            cout << "set B is proper subset of setA "<<endl;
            cout <<"-----------------------------"<<endl;

        }
    }
    if (p==true)
    {
        cout <<"-----------------------------"<<endl;
        cout<< "They are not proper subset of each others"<<endl;
        cout <<"-----------------------------"<<endl;
    }

}
void Union (int sizOf1, int sizOf2)
{
    cout <<"-----------------------------"<<endl;
    cout<< "The Union of A , B =  ";
    for(int q =0 ; q<sizOf1 ; q++)
    {
        cout<< set1[q]<<" ";
    }
    for(int q =0 ; q<sizOf2 ; q++)
    {
        int o = true;
        for(int t =0 ; t<sizOf1 ; t++)
        {
            if (set2[q]==set1[t])
            {
                o= false;
                break;
            }
        }
        if (o==true)
        {
            cout<< set2[q]<<" " ;
        }
    }
    cout<<endl;
    cout <<"-----------------------------"<<endl;
}

void intersection (int sizOf1, int sizOf2)
{
    cout <<"-----------------------------"<<endl;
    cout<< "The intersection of A , B =  ";
    for(int q =0 ; q<sizOf2 ; q++)
    {
        int o = true;
        for(int t =0 ; t<sizOf1 ; t++)
        {
            if (set2[q]==set1[t])
            {
                o= false;
                break;
            }
        }
        if (o==false)
        {
            cout<< set2[q]<<" " ;
        }
    }
    cout<<endl;
    cout <<"-----------------------------"<<endl;
}

void A_B (int sizOf1, int sizOf2)
{
    cout <<"-----------------------------"<<endl;
    cout<< "The A - B  =  ";
    for(int t =0 ; t<sizOf1 ; t++)
    {
        int o = true;
        for(int q =0 ; q<sizOf2 ; q++)
        {
            if (set2[q]==set1[t])
            {
                o= false;
                break;
            }
        }
        if (o==true)
        {
            cout<< set1[t]<<" " ;
        }
    }
    cout<<endl;
    cout <<"-----------------------------"<<endl;
}
void diffrence(int sizOf1, int sizOf2)
{

    for (int i=0; i<sizOf1; i++)
    {
        bool choice=true;
        for(int j=0; j<sizOf2; j++)
        {
            if (set1[i]==set2[j])
            {
                choice=false;
                break;
            }
        }
        if (choice)
        {
            cout << set1[i] << " ";
        }
    }
}
void power_set(int sizOf1)
{
    cout<<"the power set is :"<<endl;
    for (int i=0; i<sizOf1; ++i)
    {
        if (i==0)
            cout<<'{';
        cout<<'{'<<set1[i]<<'}'<<',';
    }
    for (int i=0; i<sizOf1; ++i)
    {
        if (i==0)
            cout<<'{';
        cout<<set1[i];
        if (i<sizOf1-1)
        {
            cout<<',';
        }
    }
    cout<<'}';
    cout<<',';
    for (int i=0; i<sizOf1; ++i)
    {
        for (int j=0; j<sizOf1; ++j)
            if (i==j)
                continue;
            else
            {
                if (i<j)
                    cout<<'{'<<set1[i]<<','<<set1[j]<<'}';
                if (i<sizOf1-1)
                    cout<<',';
            }

    }
    cout<<'{'<<" "<<'}';
    cout<<'}';
}
void power_set2(int sizOf2)
{
    cout<<"the power set is :"<<endl;
    for (int i=0; i<sizOf2; ++i)
    {
        if (i==0)
            cout<<'{';
        cout<<'{'<<set2[i]<<'}'<<',';
    }
    for (int i=0; i<sizOf2; ++i)
    {
        if (i==0)
            cout<<'{';
        cout<<set2[i];
        if (i<sizOf2-1)
        {
            cout<<',';
        }
    }
    cout<<'}';
    cout<<',';
    for (int i=0; i<sizOf2; ++i)
    {
        for (int j=0; j<sizOf2; ++j)
            if (i==j)
                continue;
            else
            {
                if (i<j)
                    cout<<'{'<<set2[i]<<','<<set2[j]<<'}';
                if (i<sizOf2-1)
                    cout<<',';
            }

    }
    cout<<'{'<<" "<<'}';
    cout<<'}';
}
void cartesian_product(int sizOf1, int sizOf2)
{
    for (int i=0; i<sizOf1; ++i)
    {
        for (int j=0; j<sizOf2; ++j)
        {
            if (i==0)
            {
                cout<<'{';
            }
            cout<<'('<<set1[i]<<','<<set2[j]<<')';
            if (i<sizOf1)
                cout<<',';

        }
    }
    cout<<'}';
}



