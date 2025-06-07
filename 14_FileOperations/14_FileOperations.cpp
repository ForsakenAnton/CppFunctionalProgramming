
#include <iostream>
#include <sstream>
#include <io.h>
#include <vector>
#include <string>

void fprintf_fscanf(const std::string& fileName)
{
    FILE* file;
    errno_t isOpen = fopen_s(&file, fileName.c_str(), "w");
    if (isOpen != NULL)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    fprintf(file, "%s", "First Line ");
    fprintf(file, "%s", "Second Line ");
    fprintf(file, "%d", 123);

    fclose(file);


    if (fopen_s(&file, fileName.c_str(), "r") != NULL)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    char data[256]{};
    int integer = 0;

    int x;

    //x = fscanf_s(file, "%s", data, sizeof(data));
    //x = fscanf_s(file, "%s", data, sizeof(data));
    //x = fscanf_s(file, "%s", data, sizeof(data));
    //x = fscanf_s(file, "%s", data, sizeof(data));
    //x = fscanf_s(file, "%s", data, sizeof(data)); // 123
    ////x = fscanf_s(file, "%d", &integer, sizeof(int));

    while (!feof(file))
    {
        long res = fscanf_s(file, "%s", data, sizeof(data)); 
        std::cout << data << "\n";
    }

    fclose(file);

    std::cout << "\n\n";
}


void fgetc_gputc(const std::string& fileName)
{
    FILE* file;
    
    if (fopen_s(&file, fileName.c_str(), "w") != NULL)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    std::string text =
        "The result of logical operators (&&, || and !)\n"
        "is either 0 or 1, but bitwise operators return an integer value. Also, \n"
        "the logical operators consider any non-zero operand as 1.\n"
        "For example, consider the following program,\n"
        "the results of & and && are different for the same operands.";

    for (int i = 0; i < text.length(); i++)
    {
        fputc(text[i], file);
    }

    fclose(file);


    if (fopen_s(&file, fileName.c_str(), "r") != NULL)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    //std::string textFromFile;
    std::stringstream ss;

    while (!feof(file))
    {
        char symbol = fgetc(file);
        //textFromFile += symbol;
        ss << symbol;

        //ungetc
    }

    //std::cout << textFromFile;
    std::cout << ss.str();

    fclose(file);

    std::cout << "\n\n";
}


void fgets_gputs(const std::string& fileName)
{
    FILE* file;

    if (fopen_s(&file, fileName.c_str(), "w") != NULL)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    std::string text =
        "The result of logical operators (&&, || and !)\n"
        "is either 0 or 1, but bitwise operators return an integer value. Also, \n"
        "the logical operators consider any non-zero operand as 1.\n"
        "For example, consider the following program,\n"
        "the results of & and && are different for the same operands.";

    fputs(text.c_str(), file);
    fclose(file);


    if (fopen_s(&file, fileName.c_str(), "r") != NULL)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    std::stringstream ss;

    while (!feof(file))
    {
        char line[256];
        fgets(line, 255, file);

        ss << line;
    }

    fclose(file);

    std::cout << ss.str();

    std::cout << "\n\n";
}


void fseek(const std::string& fileName)
{
    FILE* file;

    if (fopen_s(&file, fileName.c_str(), "r+") != 0)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    //fseek(file, 0, SEEK_SET);

    int symbol;
    while ((symbol = fgetc(file)) != EOF)
    {
        if ((char)symbol == ' ')
        {
            fseek(file, -1, SEEK_CUR);
            fputc('_', file);

            fflush(file); // (!)
        }
    }

    fclose(file);
}


int fpeek(FILE* stream)
{
    int symlol;
    symlol = fgetc(stream);
    ungetc(symlol, stream);

    return symlol;
}

void fwrite_fread(const std::string& fileName)
{
    FILE* file;

    if (fopen_s(&file, fileName.c_str(), "wb") != 0)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    struct Cat
    {
        char name[50];
        int age;
    };

    Cat jack{ "Jack", 3 };
    Cat lucky{ "Lucky", 5 };
    Cat lusy{ "Lusy", 4 };
    
    Cat cats[3]{ jack, lucky, lusy };

    for (const auto& c : cats)
    {
        fwrite(c.name, sizeof(c.name), 1, file);
        fwrite(&c.age, sizeof(c.age), 1, file);
    }

    fclose(file);


    if (fopen_s(&file, fileName.c_str(), "rb") != 0)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    std::vector<Cat> vCats;
    while (::fpeek(file) != -1)
    {
        vCats.push_back(Cat{});
        fread(vCats.back().name, sizeof(vCats.back().name), 1, file);
        fread(&vCats.back().age, sizeof(vCats.back().age), 1, file);
    }

    fclose(file);

    for (int i = 0; i < vCats.size(); i++)
    {
        std::cout << vCats[i].name << " - " << vCats[i].age << "\n";
    }
}


void showDirectory(const std::string& directory)
{
    std::string mask;
    std::cout << "Enter the file name or mask aka '*.' or '*.txt' that you want to search:\n";
    std::getline(std::cin, mask);
    std::string fullPath = directory + mask; // for example C:/myDir/*.txt

    _finddata_t fileInfo;
    
    intptr_t done = _findfirst64i32(fullPath.c_str(), &fileInfo);
    if (done == -1)
    {
        std::cout << "There are no files in the directory\n\n";
        return;
    }

    do
    {
        std::cout << fileInfo.name << "\n";
        std::cout << fileInfo.size << "\n";
        std::cout << fileInfo.time_access << "\n";
        std::cout << fileInfo.attrib << "\n";
        std::cout << fileInfo.time_create << "\n";
        std::cout << fileInfo.time_write << "\n\n";
    } 
    while (_findnext64i32(done, &fileInfo) == 0);

    _findclose(done);

    std::cout << "=======================================\n\n\n";
}



int main()
{
    std::string fileName = "Example.txt";
    std::string binaryFileName = "Binary.bin";

    //fprintf_fscanf(fileName);
    //fgetc_gputc(fileName);
    //fgets_gputs(fileName);
    //fseek(fileName);

    //fwrite_fread(binaryFileName);

    showDirectory("D:/STEP/Cpp Meetings/V10_0/FundamentalsCpp_38Hours/meeting16_17_FileSystem/");
}
