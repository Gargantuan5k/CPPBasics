#include <iostream>

int main()
{
    std::string s1 = "Lorem ipsum dolor sit amet";
    std::string s2 = "hello world";
    char s3[50];

    std::cout << s1.size() << std::endl; // or s1.length()
    std::cout << s1.capacity() << std::endl;

    s1.resize(50);
    std::cout << s1.capacity() << std::endl;

    std::cout << s1.max_size() << std::endl;

    s1.clear();
    std::cout << (s1.empty() ? "Empty" : "Not empty") << std::endl;

    s1 = "Lorem ipsum dolor sit amet";
    s1.append(" consectetur adipiscing elit");
    std::cout << s1 << std::endl;

    s1.insert(5, "(this is index 5)");
    std::cout << s1 << std::endl;

    s2.insert(6, "awesome stuff", 8);
    std::cout << s2 << std::endl;

    s1.replace(5, 17, "(this has been replaced)");
    std::cout << s1 << std::endl;

    s1.erase(5, 24);
    std::cout << s1 << std::endl;

    s2.push_back('j');
    std::cout << s2 << std::endl;

    s2.pop_back();
    std::cout << s2 << std::endl;

    s1.swap(s2);
    std::cout << s1 << " (swapped with) " << s2 << std::endl;

    s1.copy(s3, s1.size());
    s3[s1.size()] = '\0';
    std::cout << s3 << std::endl;

    std::cout << s2.find("ipsum") << std::endl;
    std::cout << s1.find('h') << std::endl;

    std::cout << s2.find('r') << std::endl;
    std::cout << s2.rfind('r') << std::endl;

    std::cout << s1.find('z') << std::endl;
    std::cout << (s1.find('z') <= s1.size() ? "Chanracter found" : "Not found") << std::endl;

    std::cout << s2.find_first_of('r', 3) << std::endl;
    std::cout << s2.find_last_of('l') << std::endl;

    std::cout << s2.find_first_not_of("Lorem") << std::endl;

    std::cout << s1.substr(4) << std::endl;
    std::cout << s1.substr(4, 5) << std::endl;

    std::cout << s1.compare(s2) << std::endl; // equivalent of cstring::strcmp(), returns -ve if s1 lower in ASCII, 0 if equal, +ve if s1 higher in ASCII

    std::cout << s1.at(3); // s1[3]

    std::cout << s1.front() << std::endl;
    std::cout << s1.back() << std::endl;

    std::string s4 = s1 + s2;
    std::cout << s4 << std::endl;

    s2 = s2 + ". Lipsum is cool text.";
    std::cout << s2 << std::endl;

    return 0;
}