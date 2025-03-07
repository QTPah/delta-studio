#ifndef YDS_WINDOWS_AUDIO_WAVE_FILE_H
#define YDS_WINDOWS_AUDIO_WAVE_FILE_H

#include "yds_audio_file.h"

#define NOMINMAX
#include <Windows.h>

class ysWindowsAudioWaveFile : public ysAudioFile {
public:
    ysWindowsAudioWaveFile();
    ~ysWindowsAudioWaveFile();

    virtual Error OpenFile(const wchar_t *fname) override;
    virtual Error CloseFile();

protected:
    virtual Error GenericRead(SampleOffset offset, SampleOffset size, void *buffer);

    HMMIO m_fileHandle;
    unsigned int m_dataSegmentOffset;
};

#endif /* YDS_WINDOWS_AUDIO_WAVE_FILE_H */
