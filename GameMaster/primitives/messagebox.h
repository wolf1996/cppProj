#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <string>

class MessageBox
{
public:
    MessageBox();
    void SetText(const std::string& );
    std::string GetText();
    void Show();
private:
    std::string text_;
};

#endif // MESSAGEBOX_H
