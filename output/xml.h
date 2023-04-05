#ifndef XML_H
#include "stdafx.h"
#include "tchar.h"
#define XML_H
#endif // !XM

#using <mscorlib.dll>
#using <System.xml.dll>

using namespace System;
using namespace System::Xml;

void _tmain(void)
{
    XmlTextReader* reader = new XmlTextReader ("books.xml");

    while (reader->Read())
    {
        switch (reader->NodeType)
        {
            case XmlNodeType::Element: // The node is an element.
                Console::Write("<{0}", reader->Name);
  
                while (reader->MoveToNextAttribute()) // Read the attributes.
                    Console::Write(" {0}='{1}'", reader->Name, reader->Value);
                Console::WriteLine(">");
                break;
            case XmlNodeType::Text: //Display the text in each element.
                Console::WriteLine (reader->Value);
                break;
            case XmlNodeType::EndElement: //Display the end of the element.
                Console::Write("</{0}", reader->Name);
                Console::WriteLine(">");
                break;
        }
    }
    Console::ReadLine();
}
struct xml
{
    char* path;
    char* salida;

    xml(char* path){
        //XmlTextReader* reader = new XmlTextReader (path);
    }
    
};
