#pragma once

#include <JuceHeader.h>

namespace Ids
{
#define DECLARE_ID(name)      const Identifier name (#name)

    DECLARE_ID (file);

    const Identifier title ("title");
    const Identifier message  ("message");

    const Identifier dataType ("Data");
    const Identifier messageType ("Message");

    #undef DECLARE_ID
};

class Data
{
public:
    Data()
    {
    }

    Data(String json)
    {
        updateFromJSON (json);
    }

    Result updateFromJSON (String json)
    {
        DBG ("updateFromJSON");

        var dataVar;
        Result result = JSON::parse (json, dataVar);
        DBG ("Got data: " << dataVar.toString());

        if (result.wasOk())
        {
            dataValueTree = ValueTree (Ids::dataType);
            Array<var>* dataArray = dataVar.getArray();

            for (auto dataItem : *dataArray)
            {
                ValueTree messageValueTree(Ids::messageType);
                messageValueTree.setProperty(Ids::title, dataItem.getProperty(Ids::title, "Untitled"), nullptr);
                messageValueTree.setProperty(Ids::message, dataItem.getProperty(Ids::message, "Empty message"), nullptr);

                DBG ("adding message: " << messageValueTree.toXmlString());
                dataValueTree.addChild (messageValueTree, -1, nullptr);
            }
        }
        else
        {
            DBG ("!!!!!!! error parsing JSON");
            DBG (result.getErrorMessage());
        }
        return result;
    }

    String toJson() noexcept
    {
        Array<var> varItems;

        for (int i = 0; i < dataValueTree.getNumChildren(); ++i)
        {
            DynamicObject* obj = new DynamicObject();
            obj->setProperty (Ids::title, dataValueTree.getChild(i).getProperty(Ids::title));
            obj->setProperty (Ids::message, dataValueTree.getChild(i).getProperty(Ids::message));
            var item (obj);
            varItems.add (item);
        }
        return JSON::toString (var (varItems));
    }

    ValueTree & getValueTree()
    {
        return dataValueTree;
    }

    static String getTestString()
    {
        return String("[\n"
                      "  {\n"
                      "    \"title\": \"Radiantix\",\n"
                      "    \"message\": \"Occaecat ullamco amet ea sit ex incididunt enim.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Imaginart\",\n"
                      "    \"message\": \"Officia eiusmod laborum qui irure tempor velit qui anim ullamco pariatur veniam occaecat ex.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Futurize\",\n"
                      "    \"message\": \"Excepteur nulla ex sit cupidatat aute exercitation veniam.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Entogrok\",\n"
                      "    \"message\": \"Esse ex id incididunt cillum eiusmod est sint proident consectetur.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Mitroc\",\n"
                      "    \"message\": \"Deserunt proident adipisicing commodo aliquip irure quis non do nostrud labore ex officia esse.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Architax\",\n"
                      "    \"message\": \"Eiusmod mollit duis esse magna ipsum pariatur minim quis ea cupidatat reprehenderit aliqua ipsum.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Geekmosis\",\n"
                      "    \"message\": \"Duis exercitation fugiat id sit ipsum adipisicing cupidatat irure anim.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Baluba\",\n"
                      "    \"message\": \"Commodo ut proident et excepteur ut ex ex.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Zillactic\",\n"
                      "    \"message\": \"Non exercitation deserunt aliquip enim deserunt ut fugiat voluptate quis esse fugiat aute cillum laborum.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Dragbot\",\n"
                      "    \"message\": \"Consectetur non eu in irure Lorem consequat.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Qualitern\",\n"
                      "    \"message\": \"Nisi enim anim commodo ea ullamco magna.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Hinway\",\n"
                      "    \"message\": \"Quis voluptate ex eu culpa nisi pariatur anim.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Hairport\",\n"
                      "    \"message\": \"Culpa sunt eu excepteur ullamco excepteur incididunt esse ut amet dolore elit duis mollit.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Zolarity\",\n"
                      "    \"message\": \"Irure sit laboris adipisicing consequat ea dolor pariatur ullamco.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Accidency\",\n"
                      "    \"message\": \"Minim ut eu nostrud esse ex labore.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Quadeebo\",\n"
                      "    \"message\": \"Reprehenderit minim Lorem proident tempor.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Pathways\",\n"
                      "    \"message\": \"Reprehenderit fugiat velit est in fugiat labore dolor qui reprehenderit ad aute.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Solgan\",\n"
                      "    \"message\": \"Nisi ut occaecat duis mollit eiusmod exercitation pariatur qui ea.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Buzzworks\",\n"
                      "    \"message\": \"Qui irure sint occaecat cillum aute est nisi ipsum fugiat duis.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Senmei\",\n"
                      "    \"message\": \"Aliqua aliquip nulla adipisicing reprehenderit tempor officia minim.\"\n"
                      "  },\n"
                      "  {\n"
                      "    \"title\": \"Mangelica\",\n"
                      "    \"message\": \"Pariatur ipsum qui eu sunt duis excepteur ipsum.\"\n"
                      "  }\n"
                      "]");
    }
    
private:
    String title;
    ValueTree dataValueTree;
    var data;
};
