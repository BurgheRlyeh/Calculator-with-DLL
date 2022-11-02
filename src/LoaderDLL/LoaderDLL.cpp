#include "LoaderDLL.h"

std::list<FARPROC>* LoaderDLL::getFromDLLs(const std::string& dir, const std::string& entityName) {
    auto entities = new std::list<FARPROC>;

    for (const auto& file : std::filesystem::directory_iterator(dir)) {
        try {
            // get entity pointer from dll
            auto entity = GetProcAddress(
                    LoadLibrary(file.path().string().c_str()),
                    entityName.c_str()
            );
            // insert pointer to list
            entities->push_back(entity);
        }
        catch (std::exception& e) {}
    }

    return entities;
}
