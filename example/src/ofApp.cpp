//
// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


struct MyRecord
{
    uint8_t x, y;
    float z;
    
    template <class Archive>
    void serialize( Archive & ar )
    {
        ar( x, y, z );
    }
};

struct SomeData
{
    int32_t id;
    std::shared_ptr<std::unordered_map<uint32_t, MyRecord>> data;
    
    template <class Archive>
    void save( Archive & ar ) const
    {
        ar( data );
    }
    
    template <class Archive>
    void load( Archive & ar )
    {
        static int32_t idGen = 0;
        id = idGen++;
        ar( data );
    }
};

void ofApp::setup()
{
    std::ofstream os(ofToDataPath("out.cereal", true), std::ios::binary);
    cereal::BinaryOutputArchive archive( os );
    
    SomeData myData;
    archive( myData );
    
    std::cout << "Saved a file." << std::endl;
    
    ofExit();
}
