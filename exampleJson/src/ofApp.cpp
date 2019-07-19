//
// Copyright (c) 2019 Abe Pazos <https://hamoid.com>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"

struct SomeData {
    std::string name;
    std::vector<float> values;
    int age;

    template<class Archive>
    void serialize(Archive & archive) {
        // Using CEREAL_NVP is optional. When used,
        // the property names in the json file match
        // the variable names in C++. Otherwise they are
        // called value0, value1, etc
        archive(
            CEREAL_NVP(name),
            CEREAL_NVP(age),
            CEREAL_NVP(values));
    }
};

void ofApp::setup() {
    SomeData data;

    std::string path = ofToDataPath("data.json", true);

    if(ofFile(path).exists()) {
        // Read
        std::ifstream stream(path);
        cereal::JSONInputArchive archive(stream);
        archive(CEREAL_NVP(data));
    } else {
        data.name = "Trantor";
        data.age = 1;
    }

    data.age++;
    data.values.push_back(ofRandomuf());

    {
        // Write
        std::ofstream stream(path);
        cereal::JSONOutputArchive archive(stream);
        archive(CEREAL_NVP(data));
    }

    ofLog() << "File updated. Check " << path;

    ofExit();
}
