#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;


enum Num_of_commands {
    INPUT = 1,
    PRINT,
    SEARCH,
    ADD,
    CHANGE,
    DELETE,
    SORTING,
    INPUT_TEXT,
    INPUT_BIN,
    PRINT_TEXT,
    TEXT_BIN,
    EXIT = 0
};


const int SIZE = 20;
const int NAME_SIZE = 50;
const int CLASSE_SIZE = 20;
const int SUBJECT_SIZE = 20;




struct student {
    struct {
        char surname[NAME_SIZE]{ "-" };
        char name[NAME_SIZE]{ "-" };
        char middle_name[NAME_SIZE]{ "-" };

    }f_i_o{};

    int course{};
    char classe[CLASSE_SIZE]{ "-" };
    int enter_year{};
    struct {
        int math_analysis{};
        int high_level_programming{};
        int analyte_geometry{};
        int engineer_graphics{};
        int theor_inf{};
    } subjects{};
};

student group[SIZE];
void input(int);
void print(int);
void search(int);
int add(int);
void change(int);
int delete_student(int);
void sorted(int);
void out_file(int);
void in_file(int&);
void text_bin(int&);
void in_bin(int&);

int main() {
    system("chcp 1251 >> null");
    int command{ -1 }, size{ 1 };
    cout << "-----------------------------MENU-----------------------------";
    do {
        cout << "\n1 - ������ ������ ������ ��������� c ����������\n";
        cout << "2 - ����������� ������ ���������\n";
        cout << "3 - ������� ���������, ���������� 2 �� ���� ���������\n";
        cout << "4 - �������� ��������.\n";
        cout << "5 - �������� ������ � ��������\n";
        cout << "6 - ������� ������ � ��������\n";
        cout << "7 - ����������� ���������\n";
        cout << "8 - ���� ���������� �� ���������� ����� (�������� ���� ������)\n";
        cout << "9 - ���� ���������� �� ��������� ����� (�������� ���� ������)\n";
        cout << "10 - ����� ���� ������ � ��������� ����,\n";
        cout << "11 - ������� ����������� ���������� ����� � �������� ����,\n";
        cout << "0 - ����� �� ����\n";

        cin >> command;
        switch (command) {
        case INPUT:
            cout << "������� ������� ���� � ����������\n";
            input(size);

            break;
        case PRINT:
            cout << "������� ������� ����� �� �����\n";
            print(size);
            break;
        case SEARCH:
            cout << "������� ������� ����� �� �������\n\n";
            search(size);
            break;
        case ADD:
            cout << "������� ������� ���������� ������ � ��������\n";
            size = add(size);

            break;
        case CHANGE:
            cout << "������� ������� ��������� ������ � ��������\n";
            change(size);
            break;
        case DELETE:
            cout << "������� ������� �������� ������ � ��������\n";
            size = delete_student(size);
            break;
        case SORTING:
            cout << "������� ������� ����������\n";
            sorted(size);


            break;
        case INPUT_TEXT:
            cout << "������� ������� \n";
            in_file(size);
            break;
        case INPUT_BIN:
            cout << "������� ������� EXIT\n";
            in_bin(size);
            break;
        case PRINT_TEXT:
            cout << "������� ������� �������� ���� ������ � ��������� ����\n";
            out_file(size);
            break;
        case TEXT_BIN:
            cout << "������� ������� EXIT\n";
            text_bin(size);
            break;
        case EXIT:
            cout << "������� ������� EXIT\n";
            break;
        default:
            cout << "������� �������� �������. ���������� ��� ���.\n";
        }
    } while (command);

    return 0;
}

void input(int size) {
    for (int i{ 0 }; i < size; i++) {
        cout << "\n������� ������ �������� �" << i + 1;
        cout << "\n������� �.�.� ��������: ";
        cout << "\n\t������� �������: ";
        cin.ignore();
        cin.getline(group[i].f_i_o.surname, NAME_SIZE);
        cout << "\t������� ���: ";
        cin.getline(group[i].f_i_o.name, NAME_SIZE);
        cout << "\t������� ��������: ";
        cin.getline(group[i].f_i_o.middle_name, NAME_SIZE);
        cout << "������� ���� ��������: ";
        cin >> group[i].course;
        while ((group[i].course < 1) || (group[i].course > 6)) {
            cout << "������ �����������.��������� �������.\n������� ���� ��������: ";
            cin >> group[i].course;
        }
        cout << "������� ������ ��������: ";
        cin.ignore();
        cin.getline(group[i].classe, CLASSE_SIZE);

        cout << "������� ��� �����������: ";
        cin >> group[i].enter_year;
        while ((group[i].enter_year < 2017) || (group[i].enter_year > 2022)) {
            cout << "������ �����������.��������� �������.\n������� ��� �����������: ";
            cin >> group[i].enter_year;
        }

        cout << "������� ������ �� ���������: ";

        cout << "\n�������������� ������: ";
        cin >> group[i].subjects.math_analysis;
        while ((group[i].subjects.math_analysis < 2) || (group[i].subjects.math_analysis > 5)) {
            cout << "������ �����������.��������� �������.\n�������������� ������: ";
            cin >> group[i].subjects.math_analysis;
        }

        cout << "��������������� ����������������: ";
        cin >> group[i].subjects.high_level_programming;
        while ((group[i].subjects.high_level_programming < 2) || (group[i].subjects.high_level_programming > 5)) {
            cout << "������ �����������.��������� �������.\n��������������� ����������������: ";
            cin >> group[i].subjects.high_level_programming;
        }

        cout << "������������� ���������: ";
        cin >> group[i].subjects.analyte_geometry;
        while ((group[i].subjects.analyte_geometry < 2) || (group[i].subjects.analyte_geometry > 5)) {
            cout << "������ �����������.��������� �������.\n������������� ���������: ";
            cin >> group[i].subjects.analyte_geometry;
        }

        cout << "���������� �������: ";
        cin >> group[i].subjects.engineer_graphics;
        while ((group[i].subjects.engineer_graphics < 2) || (group[i].subjects.engineer_graphics > 5)) {
            cout << "������ �����������.��������� �������.\n���������� �������: ";
            cin >> group[i].subjects.engineer_graphics;
        }

        cout << "������������� �����������: ";
        cin >> group[i].subjects.theor_inf;
        while ((group[i].subjects.theor_inf < 2) || (group[i].subjects.theor_inf > 5)) {
            cout << "������ �����������.��������� �������.\n������������� �����������: ";
            cin >> group[i].subjects.theor_inf;
        }
    }

}

void print(int size) {
    cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "| � |" << setw(15) << "�������" << "|" << setw(15) << "���" << "|" << setw(15) << "��������" <<
        "|" << setw(4) << "����" << "|" << setw(10) << "������" << "|" << setw(17) << "��� �����������" <<
        "|" << setw(12) << "���. ������" << "|" << setw(4) << "��" << "|" << setw(12) << "������.����" <<
        "|" << setw(12) << "���.�������" << "|" << setw(12) << "�����������" << "|\n";
    cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    for (int i = 0; i < size; i++) {
        cout << "| " << i + 1;
        cout << " |" << setw(15) << group[i].f_i_o.surname << "|" << setw(15) << group[i].f_i_o.name << "|" << setw(15) << group[i].f_i_o.middle_name;
        cout << "|" << setw(4) << group[i].course;
        cout << "|" << setw(10) << group[i].classe;
        cout << "|" << setw(17) << group[i].enter_year;
        cout << "|" << setw(12) << group[i].subjects.math_analysis;
        cout << "|" << setw(4) << group[i].subjects.high_level_programming;
        cout << "|" << setw(12) << group[i].subjects.analyte_geometry;
        cout << "|" << setw(12) << group[i].subjects.engineer_graphics;
        cout << "|" << setw(12) << group[i].subjects.theor_inf << "|" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    }
}
void search(int size) {
    int count{ 0 }, flag{ 0 }, k{ 0 }, mark_two{ 2 }, j{ 0 };
    for (int i{}; i < size; i++) {
        count = 0;
        if (group[i].subjects.math_analysis == mark_two) count++;
        if (group[i].subjects.high_level_programming == mark_two) count++;
        if (group[i].subjects.analyte_geometry == mark_two) count++;
        if (group[i].subjects.engineer_graphics == mark_two) count++;
        if (group[i].subjects.theor_inf == mark_two) count++;
        if (count == 3) {
            if (flag == 0) {
                cout << "��������, ���������� 2 �� ���� ���������:\n";
                flag = 1;

            }
            cout << j + 1;
            cout << ". " << group[i].f_i_o.surname << " ";
            cout << group[i].f_i_o.name << " ";
            cout << group[i].f_i_o.middle_name;
            cout << "\t������: " << group[i].classe << endl;

        }
        else k++;
    }
    if (k == size) cout << "\n��� ���������, ���������� 2 �� ���� ���������\n";
}
int add(int size) {
    size++;
    cout << "\n������� ������ �������� �" << size;
    cout << "\n������� �.�.� ��������: ";
    cout << "\n\t������� �������: ";
    cin.ignore();
    cin.getline(group[size - 1].f_i_o.surname, NAME_SIZE);
    cout << "\t������� ���: ";
    cin.getline(group[size - 1].f_i_o.name, NAME_SIZE);
    cout << "\t������� ��������: ";
    cin.getline(group[size - 1].f_i_o.middle_name, NAME_SIZE);
    cout << "������� ���� ��������: ";
    cin >> group[size - 1].course;
    while ((group[size - 1].course < 1) || (group[size - 1].course > 6)) {
        cout << "������ �����������.��������� �������.\n������� ���� ��������: ";
        cin >> group[size - 1].course;
    }
    cout << "������� ������ ��������: ";
    cin.ignore();
    cin.getline(group[size - 1].classe, CLASSE_SIZE);

    cout << "������� ��� �����������: ";
    cin >> group[size - 1].enter_year;
    while ((group[size - 1].enter_year < 2017) || (group[size - 1].enter_year > 2022)) {
        cout << "������ �����������.��������� �������.\n������� ��� �����������: ";
        cin >> group[size - 1].enter_year;
    }

    cout << "������� ������ �� ���������: ";

    cout << "\n�������������� ������: ";
    cin >> group[size - 1].subjects.math_analysis;
    while ((group[size - 1].subjects.math_analysis < 2) || (group[size - 1].subjects.math_analysis > 5)) {
        cout << "������ �����������.��������� �������.\n�������������� ������: ";
        cin >> group[size - 1].subjects.math_analysis;
    }

    cout << "��������������� ����������������: ";
    cin >> group[size - 1].subjects.high_level_programming;
    while ((group[size - 1].subjects.high_level_programming < 2) || (group[size - 1].subjects.high_level_programming > 5)) {
        cout << "������ �����������.��������� �������.\n��������������� ����������������: ";
        cin >> group[size - 1].subjects.high_level_programming;
    }

    cout << "������������� ���������: ";
    cin >> group[size - 1].subjects.analyte_geometry;
    while ((group[size - 1].subjects.analyte_geometry < 2) || (group[size - 1].subjects.analyte_geometry > 5)) {
        cout << "������ �����������.��������� �������.\n������������� ���������: ";
        cin >> group[size - 1].subjects.analyte_geometry;
    }

    cout << "���������� �������: ";
    cin >> group[size - 1].subjects.engineer_graphics;
    while ((group[size - 1].subjects.engineer_graphics < 2) || (group[size - 1].subjects.engineer_graphics > 5)) {
        cout << "������ �����������.��������� �������.\n���������� �������: ";
        cin >> group[size - 1].subjects.engineer_graphics;
    }

    cout << "������������� �����������: ";
    cin >> group[size - 1].subjects.theor_inf;
    while ((group[size - 1].subjects.theor_inf < 2) || (group[size - 1].subjects.theor_inf > 5)) {
        cout << "������ �����������.��������� �������.\n������������� �����������: ";
        cin >> group[size - 1].subjects.theor_inf;
    }

    return size;

}
void change(int size) {
    int st, change;
    cout << "������� ����� ��������: ";
    cin >> st;
    while (st <= 0 || st > size) {
        cout << "�� ���������� ������ ��������. ���������� ��� ���.\n������� ����� ��������: ";
        cin >> st;
    }
    do {
        cin.ignore();
        cout << "��� ���������� ��������?\n";
        cout << "1 - �������\n2 - ���\n3 - ��������\n4 - ����\n5 - ������\n6 - ��� �����������\n";
        cout << "������ �� ���������:";
        cout << "\n\t7 - �������������� ������\n\t8 - ��������������� ���������������\n\t9 - ������������� ���������";
        cout << "\n\t10 - ��������� �������\n\t11 - ������������� �����������\n0 - ��������� ���������";
        cin >> change;
        cout << "\n������� ����� ������: ";
        switch (change) {
        case(1):
            cout << "������� �������: ";
            cin.getline(group[st - 1].f_i_o.surname, NAME_SIZE);// ������
            break;
        case(2):
            cout << "������� ���: ";
            cin.getline(group[st - 1].f_i_o.name, NAME_SIZE);
            break;
        case(3):
            cout << "������� ��������: ";
            cin.getline(group[st - 1].f_i_o.middle_name, NAME_SIZE);
            break;
        case(4):
            cout << "������� ���� ��������: ";
            cin >> group[st - 1].course;
            while ((group[st - 1].course < 1) || (group[st - 1].course > 6)) {
                cout << "������ �����������.��������� �������.\n������� ���� ��������: ";
                cin >> group[st].course;
            }
            break;
        case(5):
            cout << "������� ������ ��������: ";
            cin.getline(group[st - 1].classe, CLASSE_SIZE);
            break;
        case(6):
            cout << "������� ��� �����������: ";
            cin >> group[st - 1].enter_year;
            while ((group[st - 1].enter_year < 2017) || (group[st - 1].enter_year > 2022)) {
                cout << "������ �����������.��������� �������.\n������� ��� �����������: ";
                cin >> group[size - 1].enter_year;
            }
            break;
        case(7):
            cout << "\n�������������� ������: ";
            cin >> group[st - 1].subjects.math_analysis;
            while ((group[st - 1].subjects.math_analysis < 2) || (group[st - 1].subjects.math_analysis > 5)) {
                cout << "������ �����������.��������� �������.\n�������������� ������: ";
                cin >> group[size - 1].subjects.math_analysis;
            }
            break;
        case(8):
            cout << "��������������� ����������������: ";
            cin >> group[st - 1].subjects.high_level_programming;
            while ((group[st - 1].subjects.high_level_programming < 2) || (group[st - 1].subjects.high_level_programming > 5)) {
                cout << "������ �����������.��������� �������.\n��������������� ����������������: ";
                cin >> group[st - 1].subjects.high_level_programming;
            }
            break;
        case(9):
            cout << "������������� ���������: ";
            cin >> group[st - 1].subjects.analyte_geometry;
            while ((group[st - 1].subjects.analyte_geometry < 2) || (group[st - 1].subjects.analyte_geometry > 5)) {
                cout << "������ �����������.��������� �������.\n������������� ���������: ";
                cin >> group[st - 1].subjects.analyte_geometry;
            }
            break;
        case(10):
            cout << "���������� �������: ";
            cin >> group[st - 1].subjects.engineer_graphics;
            while ((group[st - 1].subjects.engineer_graphics < 2) || (group[st - 1].subjects.engineer_graphics > 5)) {
                cout << "������ �����������.��������� �������.\n���������� �������: ";
                cin >> group[st - 1].subjects.engineer_graphics;
            }
            break;
        case(11):
            cout << "������������� �����������: ";
            cin >> group[st - 1].subjects.theor_inf;
            while ((group[st - 1].subjects.theor_inf < 2) || (group[st - 1].subjects.theor_inf > 5)) {
                cout << "������ �����������.��������� �������.\n������������� �����������: ";
                cin >> group[st - 1].subjects.theor_inf;
            }
            break;
        case(0):

            break;
        default:
            cout << "����������� ������� �������.";
        }
    } while (change);
    cout << "��������� ���������";

}

int delete_student(int size) {
    int n;
    cout << "������� ����� ��������, ������ � ������� �� ������ �������: ";
    cin >> n;
    while (n <= 0 || n > size) {
        cout << "�� ���������� ������ ��������. ���������� ��� ���.\n������� ����� ��������: ";
        cin >> n;
    }

    for (int i = 0; i < size - 1; i++) {
        if (i >= n - 1) {
            group[i] = group[i + 1];
        }
    }
    size--;

    return size;
}

void sorted(int size) {
    int sort;
    double average_i, average_j;
    student temp;
    cout << "1 - ���������� �� ������� �-�\n2 - ���������� �� �������� �����\n3 - ���������� �� ���� �����������\n4 - ���������� �� �����\n5 - ������� �������������� �����������\n";
    cin >> sort;
    switch (sort) {
    case(1):
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (strcmp(group[j].f_i_o.surname, group[i].f_i_o.surname) < 0) {
                    temp = group[i];
                    group[i] = group[j];
                    group[j] = temp;
                }
        break;
    case(2):
        for (int i = 0; i < size - 1; i++) {
            average_i = (group[i].subjects.math_analysis + group[i].subjects.high_level_programming +
                group[i].subjects.analyte_geometry + group[i].subjects.engineer_graphics +
                group[i].subjects.theor_inf) / 5;
            for (int j = i + 1; j < size; j++) {
                average_j = (group[j].subjects.math_analysis + group[j].subjects.high_level_programming +
                    group[j].subjects.analyte_geometry + group[j].subjects.engineer_graphics +
                    group[j].subjects.theor_inf) / 5;
                if (average_j > average_i) {
                    temp = group[i];
                    group[i] = group[j];
                    group[j] = temp;
                }
            }
        }
        break;
    case(3):
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (group[j].enter_year > group[i].enter_year) {
                    temp = group[i];
                    group[i] = group[j];
                    group[j] = temp;
                }
            }
        }
        break;
    case(4):
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (group[j].course > group[i].course) {
                    temp = group[i];
                    group[i] = group[j];
                    group[j] = temp;
                }
            }
        }
        break;

    }
}

void out_file(int size) {
    ofstream fout("file.txt", ios_base::out | ios_base::trunc);
    if (!fout.is_open()) {
        cout << "�� ������� ������� ����.";
    }
    else {
        fout << size;
        for (int i = 0; i < size; i++) {

            fout << group[i].f_i_o.surname << endl;
            fout << group[i].f_i_o.name << endl;
            fout << group[i].f_i_o.middle_name << endl;
            fout << group[i].course << endl;
            fout << group[i].classe << endl;
            fout << group[i].enter_year << endl;
            fout << group[i].subjects.math_analysis << endl;
            fout << group[i].subjects.high_level_programming << endl;
            fout << group[i].subjects.analyte_geometry << endl;
            fout << group[i].subjects.engineer_graphics << endl;
            fout << group[i].subjects.theor_inf << endl << endl;
        }
        fout.close();
        cout << "������ ���������� � ���� file.\n";
    }
}
void in_file(int& size) {
    int i{ 0 };
    ifstream inf("file.txt");
    if (!inf.is_open()) {
        cout << "���� �� ������.\n";
    }
    else {
        inf >> size;
        for (int i = 0; i < size; i++) {
            inf >> group[i].f_i_o.surname;
            inf >> group[i].f_i_o.name;
            inf >> group[i].f_i_o.middle_name;
            inf >> group[i].course;
            inf >> group[i].classe;
            inf >> group[i].enter_year;
            inf >> group[i].subjects.math_analysis;
            inf >> group[i].subjects.high_level_programming;
            inf >> group[i].subjects.analyte_geometry;
            inf >> group[i].subjects.engineer_graphics;
            inf >> group[i].subjects.theor_inf;


        }

        inf.close();
    }
    cout << "������ ���������� �� ����� file.\n";
}
void text_bin(int& size) {
    ifstream inf("file.txt", ios::in);
    ofstream fout("file_bin.txt", ios::binary | ios::out);
    student st;
    if (inf) {
        inf >> size;
        for (int i = 0; i < size; i++) {
            inf >> st.f_i_o.surname;
            inf >> st.f_i_o.name;
            inf >> st.f_i_o.middle_name;
            inf >> st.course;
            inf >> st.classe;
            inf >> st.enter_year;
            inf >> st.subjects.math_analysis;
            inf >> st.subjects.high_level_programming;
            inf >> st.subjects.analyte_geometry;
            inf >> st.subjects.engineer_graphics;
            inf >> st.subjects.theor_inf;
            fout.write((char*)&st, sizeof(student));
        }
        fout.close();
        inf.close();
        cout << "������ ���������� � ���� file_bin.\n";
    }
}
void in_bin(int& size) {
    int i{ 0 };
    ifstream fin("file_bin.txt", ios::binary | ios::in);
    if (!fin.is_open()) {
        cout << "�� ������� ������� ����.";
    }
    else {
        while (!fin.eof()) {
            fin.read((char*)&group[i], sizeof(group[i]));
            i++;
        }
        size = i - 1;
        fin.close();
    }
}
