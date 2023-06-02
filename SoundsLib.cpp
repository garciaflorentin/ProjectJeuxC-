#include "SoundsLib.hpp"


map<string, sf::Music*> SoundsLib::_sounds;


int SoundsLib::assignSound(string filename, sf::Music* sound) {
    if (SoundsLib::_sounds.count(filename) == 0) {
        _sounds.insert({ filename, new sf::Music });

        if (!(SoundsLib::_sounds[filename]->openFromFile(filename))) { //charger le fichier
            //cout << "erreur dans le chargement de l'image " << filename << endl;
            throw runtime_error("Error loading sound " + filename);
            return EXIT_FAILURE;
        }

        return 0;
    }

    sound = SoundsLib::_sounds[filename];
    return 0;
}


sf::Music* SoundsLib::assignSound(string filename) {
    //cout << "Looking for sound " << filename << endl;
    
    if (_sounds.count(filename) == 0) {
        _sounds.insert({ filename, new sf::Music });

        if (!_sounds[filename]->openFromFile(filename)) {    //charger le fichier
            throw runtime_error("Error loading sound " + filename);
        }
    }

    //cout << "Sound files loaded : " << _sounds.size() << endl;

    return _sounds[filename];
}
