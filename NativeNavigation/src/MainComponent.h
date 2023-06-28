#pragma once

#include <JuceHeader.h>
#include "Data.h"

class MainContentComponent   : public Component
{
public:
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();

    String title;
    String message;
    Data data;

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
