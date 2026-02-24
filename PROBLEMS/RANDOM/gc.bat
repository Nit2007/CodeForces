function gpp {
    param($file)

    if (Test-Path bin.exe) {
        Remove-Item bin.exe
    }

    g++ $file -std=c++17 -o bin.exe
}
