
#include <iostream>
#include <sstream>

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

    if (fopen_s(&file, fileName.c_str(), "a+") != 0)
    {
        std::cout << "Error while opening the file '" << fileName << "'. 0_o";
        return;
    }

    fseek(file, 0, SEEK_SET);

    int symbol;
    while ((symbol = fgetc(file)) != EOF)
    {
        if ((char)symbol == ' ')
        {
            fseek(file, -1, SEEK_CUR);
            fputc('_', file);
        }
    }

    fclose(file);
}



int main()
{
    std::string fileName = "Example.txt";

    //fprintf_fscanf(fileName);
    //fgetc_gputc(fileName);
    fgets_gputs(fileName);
    fseek(fileName);
}

