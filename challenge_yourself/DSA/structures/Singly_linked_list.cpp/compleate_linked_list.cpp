#include<iostream>
using namespace std;

struct node{
  int roll_num;
  string name;
  struct node *next;
}*head = NULL,*last;

struct node* create(int roll,string nam){
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->roll_num = roll;
  new_node->name = nam;
  new_node->next = NULL;
  return new_node;
}
void all_student(struct node *pt){
  int arr[][2] = {
  {1,AAHANA SACHDEVA},
  {2,AANYA GUPTA},
  {3 ,AANYA SINGH},
  {4 ,AARNA SRIVASTAVA},
  {5 ,ADITI},
  {6 ,ADYASHA MAHARANA},
  {7 ,AISHNA GURNANI},
  {8 ,ANIKA GOEL},
  {9 ,ANUSHKA TRIPATHI},
  {10,  ANVITA TRIPATHI},
  {11,  ANWITA THAKUR},
  {12,  ANYUKTI SRIVASTAVA},
  {13,  ARADHYA SAHU },
  {14,  ARADHYA SINGH },
  {15,  ARADHYA SINGH },
  {16,  ARIKA MISHRA},
  {17,  ASHWIKA MISHRA}, 
  {18,  ATIYA FATIMA },
  {19,  AVANTIKA SINGH },
  {20, AVIKA RATHORE},
  {21,  AZKA ARIF},
  {22,  DHAANYA SHARMA},
  {23,  DHANYA SHUKLA},
  {24,  FATIMA AMAAN KHAN},
  {25,  GAURAVI AGRAWAL},
  {26,  IPSHITA SURESH},
  {27,  ISHANI SRIVASTAVA },
  {28,  ISHITA KHANAL},
  {29,  JANNAT KHAN},
  {30, JOANNA ROSH},
  {31,  KAVYA SINGH},
  {32,  KRITIKA PANDEY},
  {33,  KRITIKA SINGH},
  {34,  LAIBA HUMAID},
  {35,  LAIBAH SHAIKH},
  {36, MAHAM KAZMI},
  {37,  MARIYAM HUSSAIN},
  {38,  MARIYAM JUNAID},
  {39,  MASEERA SIDDIQUI},
  {40,  NETRA MISHRA},
  {41,  NIMISHA ANAND},
  {42,  PAWNI KESARWANI},
  {43,  PRATYUSHA SONKAR},
  {44,  RABIA AHMAD},
  {45,  SAMAN ZAID},
  {46,  SAMRIDDHI SINGH}, 
  {47,  SHIVANGI PANDEY},
  {48, SHOA RIZVI},
  {49,  SHYLA SONKAR},
  {50,  TANISHA HUSSAIN},
  {51,  TWISHA CHOPRA},
  {52,  UNNATI MISHRA},
  {53,  UNNATI SINGH},
  {54, VACHYA AGRAHARI},
  {55,  VAISHNAVI CHAUDHARY}, 
  {56,  VRIDDHI KUSHWAHA},
  {57,  VRINDA UPADHYAY},
  {58,  ZAINAB FATMA},
  {59,  ZAINAB SIDDIQUI},
  {60,  ZUFISHA SUHAIL}
  };
  int size = sizeof(arr)/sizeof(arr[0]);
  for (int i=0;i<size;i++){
    if (head == NULL){
      struct node *new_node;
      new_node->roll_num = arr[i][0];
      new_node->name = arr[i][1];
      head = new_node;
      last = head;
    }
    else{
      struct node *new_node;
      new_node = create(arr[i][0],arr[i][2]);
    }
  }
}

void insert(struct node *pt,int roll,string nam,int pos){
  struct node *q;
  q = NULL;
  while (pos>0){
    q = pt;
    pt=pt->next;
    pos--;
  }
  struct node *new_node;
  new_node = create(roll,nam);
  new_node->next = q->next;
  q->next = new_node;

}
void insert_first(struct node *pt,int roll,string nam){
  struct node *new_node;
  new_node = create(roll,nam);
  new_node->next = pt;
  pt = new_node;
}
void insert_last(struct node *pt,int roll,string nam){
  struct node *q;
  q = NULL;
  while (pt->next != NULL){
    q = pt;
    pt = pt->next;
  }
  struct node *new_node;
  new_node = create(roll,nam);
  new_node->next = q->next;
  q->next = new_node;
}

void deleate_roll(struct node *pt,int roll){
  struct node *q;
  q = NULL;
  while (pt != NULL && pt->roll_num != roll){
    q = pt;
    pt = pt->next;
  }
  struct node *temp;
  temp = pt;
  q->next = pt->next;
  delete temp;
}

void deleate_name(struct node *pt,string nam){
  struct node *q;
  q = NULL;
  while (q && pt->name != nam){
    q = pt;
    pt = pt->next;
  }
  struct node *temp;
  temp = pt;
  q->next = pt->next;
  delete temp;
}

void close(){
  return;
}
int count_student(struct node *pt){
  int count = 0;
  while (pt!= NULL){
    count++;
    pt=pt->next;
  }
  return count;
}
void mark_atendence(struct node*pt,int arr[]){
  int size = sizeof(arr)/sizeof(arr[0]);
  int before_total = count_student(pt);
  for (int i=0;i<size;i++){
    deleate_roll(pt,arr[i]);
  }
  int after_total = count_student(pt);
  cout << "Total student Present: " << before_total << endl;
  cout << "Total student absent: "<< before_total- after_total << endl;
  cout << "thanks for taking atendence.";

}
void remove_duplicates(struct node *pt){
  struct node *p,*q;
  p = pt;
  q = pt->next;
  while (q!=NULL){
    if (p->roll_num != q->roll_num){
      p = q;
      q = q->next;
    }
    else{
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}
void reverse(struct node *pt){
  struct node *temp;
  int arr[100];
  int i=0;
  temp = pt;
  while (temp!=NULL){
    arr[i++] = temp->roll_num;
    temp = temp->next;
  }
  i--;
  temp = pt;
  while (temp!=NULL){
    arr[i--] = temp->roll_num;
    temp = temp->next;
  }
}

void reverse(struct node *pt){
  struct node *p,*q,*r;
  p = head;
  q = NULL;
  r = NULL;
  while (p!=NULL){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q; // here we are updating last poiter to the head pointer.

}



void print_funcation(){
  cout << "Hi......."<< endl;
  string day;
  cout << "How was your day."<<endl << "good or bad...........please write"<< endl;
  cin >> day;
  if (day == "good"){
    cout << "That great. Have a nice day ahead."<< endl;
  }
  else{
    cout << "oww. i hope you are doing good"<< endl;
  }
  cout << "I hope you are great."<< endl;
  cout << "okay Lets back to the work." << endl;
  cout << "What you wanna today..."<< endl;
  cout << "Enter choice>>>>" << endl;
  cout << "1. Admission related." << endl;
  cout << "      1. New_student Admission."<< endl;
  cout << "      2. Set New_student to specific roll number."<< endl;
  cout << "      3. Set New_student to first roll number."<< endl;
  cout << "      4. Set New_student to last roll number."<< endl;
  cout << "      5. Remove student by name. "<< endl;
  cout << "      6. Remove student by roll_number."<< endl;
  cout << "2. Marking Atendence."<< endl;
  cout << "3. Arrange in reverse order." << endl;

  cout << "6. Please close."<< endl;


}

int main(){
 
  int roll;
  string name;
  
     cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Welcome to Student Management System>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<< endl;
     cout << "............................................................................................................."<< endl;
     cout << "............................................................................................................."<< endl;
     print_funcation();



  
}
