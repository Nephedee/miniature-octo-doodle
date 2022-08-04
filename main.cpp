#include <iostream>
#include <map>
#include <string>
#include <cpr/cpr.h>
#include <vector>

int main() {
    std::string in1, in2;
    std::map<std::string, std::string> o;
    cpr::Pair p("", "");
    cpr::Response r;
    std::vector<cpr::Pair> inputs;
    while(1){
    std::cout << "\nArg1 = " << std::endl;
    std::cin >> in1;
    if(in1 == "post") {
        r = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload(inputs.begin(), inputs.end()));
        std::cout <<std::endl << r.text;
        continue;
    } else
        if(in1 == "get"){
         std::string urlGet = "http://httpbin.org/get";
            for(int i = 0; i < inputs.size(); i++){
             if(i == 0)
                 urlGet += "?";
                 urlGet += inputs[i].key;
                 urlGet += "=";
                 urlGet += inputs[i].value;
                 urlGet += "&";
            }
        r = cpr::Get(cpr::Url(urlGet));
        std::cout << r.text;
        continue;
    };
    std::cout << "\nArg2 = " << std::endl;
    std::cin >> in2;
    p.key = in1;
    p.value = in2;
    inputs.push_back(p);
    }
    return 0;
}
