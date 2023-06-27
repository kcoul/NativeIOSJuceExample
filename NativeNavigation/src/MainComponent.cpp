#include "MainComponent.h"

MainContentComponent::MainContentComponent()
{
    setSize (600, 400);

    title = "title";

    message = "message";

    data = Data(Data::getTestString());
}

MainContentComponent::~MainContentComponent()
{

}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    g.setFont (Font (24.0f));
    g.setColour (Colours::orange);
    g.drawText (title, getLocalBounds(), Justification::centredTop, true);

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText (message, getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
}
