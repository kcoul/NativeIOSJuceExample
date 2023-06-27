#pragma once

#include <JuceHeader.h>
#include "MainComponent.h"

class MainWindow : public DocumentWindow
{
public:
    MainWindow (String name);
    void closeButtonPressed() override;
    static void addComponentToUIView (Component& comp, void* uiView);
    
private:
    SharedResourcePointer<MainContentComponent> mainComponent;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};
