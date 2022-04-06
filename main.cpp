#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;



class Item{

public:
    string name;
    float cj;
    char vatTaxType;
    int amountSold;

public:
    Item(string n,float c,char vt,int ats){
        name=n;
        cj=c;
        vatTaxType=vt;
        amountSold=ats;
    }
};
class Invoice{
private:
    string nipNr;
    string buyer;
    vector<Item> soldItems;
public:
    Invoice(string n,string b){
        nipNr=n;
        b=buyer;
    }
    void add_item(Item it){
        soldItems.push_back(it);
    }
    friend std::ostream &operator<<( std::ostream &output, const Invoice &i );
};
std::ostream &operator<<( std::ostream &output, const Invoice &i ) {

            output <<"---------------VAT invoice---------------------------"<<endl;
            output <<"====================================================="<<endl<<endl;
            output <<setw(18)<<"c.j."<<setw(8)<<"VAT"<<setw(8)<<"il"<<setw(8)<<"net"<<setw(8)<<"total"<<endl;
            int nr=1;
            float sumNet=0;
            float sumTotal=0;
            for(auto val:i.soldItems){
                output <<nr<<"."<<val.name<<setw(16-size(val.name))<<val.cj<<setw(8)<<val.vatTaxType<<"|"<<setw(8)<<val.amountSold<<"|"<<setw(8)<<val.cj*val.amountSold<<"|"<<setw(8);
                float c=0;
                if(val.vatTaxType=='A'){
                    c=1.23;
                }else if(val.vatTaxType=='B'){
                    c=1.08;
                }else
                {
                    c=1.0;
                }
                output <<val.cj*val.amountSold*c<<endl;
                nr++;
                sumNet+=val.cj*val.amountSold;
                sumTotal+=val.cj*val.amountSold*c;
            }

            output <<endl<<"---------------------------------------- TOTAL ------"<<endl;
            output <<setw(43)<<sumNet<<" | "<<sumTotal<<endl;

         return output;
      }

int main()
{
    Invoice inv("7770003699", "0123456789");
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    cout << setprecision(3);
    std::cout << inv << std::endl;
}
