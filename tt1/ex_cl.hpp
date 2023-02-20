// Example Class
#include <string>
#include <iostream>

class ExComp{
    private:
        int             val;
        unsigned int    ID;
        std::string     txt;
    public:
        static int      lastID;
        static int      duplicates;
        ExComp(void){};
        ExComp(int v, const std::string& input);
        ~ExComp(){};
        void    print_txt();
        int     ret_val()  {return val;};
        bool    operator== (const ExComp& cmp);
        bool    operator== (const int cmp);
        bool    operator<  (const ExComp& cmp);
        bool    operator<  (const int cmp);
        bool    operator>  (const ExComp& cmp);
        bool    operator>  (const int cmp);
        friend  std::ostream& operator<<(std::ostream& os, const ExComp& prnt);
};

int ExComp::lastID = 0;
int ExComp::duplicates = 0;

ExComp::ExComp(int v, const std::string& input){
    this->val = v;
    this->txt = input;
    lastID++;
    this->ID = lastID;
}

void ExComp::print_txt(){
    std::cout<< "Obj.ID=" << this->ID << "|Text=" << this->txt << std::endl; }

bool ExComp::operator==(const int cmp){
    std::cout<< this->val << " vs " << cmp << std::endl;
    if (this->val == cmp) duplicates++;
    return this->val == cmp; }

bool ExComp::operator==(const ExComp& cmp){
    std::cout<< this->val << " vs " << cmp.val << std::endl;
    if (this->val == cmp.val) duplicates++;
    return this->val == cmp.val; }

bool ExComp::operator< (const ExComp& cmp){
    return this->val < cmp.val; }

bool ExComp::operator< (const int cmp){
    return this->val < cmp; }

bool ExComp::operator> (const ExComp& cmp){
    return this->val > cmp.val; }

bool ExComp::operator> (const int cmp){
    return this->val > cmp; }

std::ostream& operator<<(std::ostream& os, const ExComp& prnt){
    os << "|ID=" << prnt.ID << "|txt=" << prnt.txt << "|val=" << prnt.val;
    return os;
}
