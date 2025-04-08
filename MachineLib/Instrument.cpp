/**
 * @file Instrument.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "Instrument.h"
Instrument::Instrument(std::wstring resourcesDir, ma_engine* audioEngine, std::wstring audioFile)
{
    auto result = ma_sound_init_from_file(audioEngine, wxString(resourcesDir + audioFile), 0, NULL, NULL, &mSound);
    if (result != MA_SUCCESS)
    {
        wxString msg;
        msg.Printf(L"Unable to load audio file %s - %d", audioFile, result);
        wxMessageBox( msg, wxT("miniaudio failure"), wxICON_ERROR);
    }
}
/**
 * Destructor
 */
Instrument::~Instrument()
{
    if(ma_sound_is_playing(&mSound))
    {
        ma_sound_stop(&mSound);
    }

    ma_sound_uninit(&mSound);
}

void Instrument::PlaySound()
{
    // If the sound is already playing, stop it first
    if(ma_sound_is_playing(&mSound))
    {
        ma_sound_stop(&mSound);
    }

    // Always rewind to the beginning before playing
    ma_sound_seek_to_pcm_frame(&mSound, 0);

    // And play the sound!
    ma_sound_start(&mSound);
}




