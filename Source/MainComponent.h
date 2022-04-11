#pragma once

#include <JuceHeader.h>

class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override = default;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    juce::TextButton button{"I'm a button!"};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
