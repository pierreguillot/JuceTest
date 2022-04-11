#include "MainComponent.h"

MainComponent::MainComponent()
{
    button.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::red);
    button.onStateChange = [this]()
    {
        if(button.isMouseOver())
        {
            button.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::green);
        }
        else
        {
            button.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::red);
        }
    };
    addAndMakeVisible(button);
    setSize(600, 400);
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    button.setBounds(getLocalBounds().withSizeKeepingCentre(100, 32));
}
