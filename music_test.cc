#include "AudioClip.h"
#include <iostream>
#include <fstream>
#include "Bridges.h"
#include <math.h>

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges = Bridges(8, "Luke_Olson1", "1182958906629");



    // Title, description
        bridges.setTitle("Founding Freedom Game Music");
        bridges.setDescription("Founding Freedom Game Music");

        // Create the audio clip object from a .wav file
        // We do this by passing the path to the file into the constructor
        // Change the path to be any .wav file on your system.
	cout << "before audio file name" << endl;
        AudioClip oldAudioClip = AudioClip("2_bar_fight.wav");
	cout << "after audio file name" << endl;

        // Create a new audio clip object to store our changes on.
        // Copy the sample count, sample bit depth, and sample rate from the old clip.
       /* AudioClip newAudioClip = AudioClip(oldAudioClip.getSampleCount(), 1,
                oldAudioClip.getSampleBits(), oldAudioClip.getSampleRate());

        // Iterate through every sample in the clip
        for (int i = 0; i < newAudioClip.getSampleCount(); i++){
            // Get the sample at i in the first (and only) channel.
            int sampleValue = oldAudioClip.getSample(0, i);
            // Halve the value of the sample
            int newSampleValue = sampleValue / 2;
            // Set the sample at i to the new value
            newAudioClip.setSample(0, i, newSampleValue);
        }
*/
        // Visualize the original audio clip
        bridges.setDataStructure(oldAudioClip);
        bridges.visualize();

        //Visualize the new audio clip
        //bridges.setDataStructure(newAudioClip);
       // bridges.visualize();
    return 0;
}
