#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <imgui.h>
#include <imgui-SFML.h>
#include <TGUI/TGUI.hpp>

#include "Pikachur_sprite.h"
#include "box50x50_sprite.h"
#include "Pikachu_barra.h"
#include "sonic_music.h"
#include "sewer_font.h"

#include <iostream>
using namespace std;

std::string nome = "Jogo do Herbert";
int        ancho = 700;//largura
int         alto = 500;//altura
int         bits = 32;//bits
int       frameR = 0;
int       frameL = 70;
float    divisor = 1.5;
float  posicionX = 100.0;
float  posicionY = 400.0;
float velocidadX = 0.0;
float velocidadY = 0.0;
float       velx = 0.0;
float       vely = 13.0;
float      suelo = 420.0;
float   gravedad = 1.5;
bool    onGround = false;
int  jumpCounter = 0;

sf::Texture tPikachu;
sf::Texture tBox;

sf::Sprite pikachu;
sf::Sprite box;

//Prototipos
void Update();
void pivot(sf::Sprite& sprite);
void MoveLeft();
void StartJump();
void MoveRight();
void game_run();
void menu();
void drawButtons();

int main()
{
    menu();
}

void game_run()
{
    sf::RenderWindow window(sf::VideoMode ( ancho, alto, bits ),  nome.c_str());
    window.setFramerateLimit (30);

    sf::Music music;
    if(!music.openFromMemory(samples, 2126628))std::cout << "error" << std::endl;
    music.play();

    tPikachu.loadFromMemory(data, 3345);
    pikachu.setTextureRect(sf::IntRect(0, 0, 70, 70));
    pikachu.setTexture(tPikachu);
    pivot(pikachu);

    tBox.loadFromMemory(data2, 1158);
    box.setTextureRect(sf::IntRect(0+1, 0, 50, 50));
    box.setTexture(tBox);
    pivot(box);

    window.setKeyRepeatEnabled ( false );
    sf::Clock clock;
    sf::Time tempo = sf::milliseconds(10);
    while ( window.isOpen() )
    {
        sf::Time elapsed1 = clock.getElapsedTime();
        if( elapsed1 >= tempo )
        {
            sf::Event event;
            while (window.pollEvent (event))
            {
                if (event.type == sf::Event::Closed)window.close();
            }
            if ( event.type == sf::Event::KeyReleased )
            {
                pikachu.setTextureRect ( sf::IntRect ( 0, 0, 70, 70 ) );
                //frameR = 0;
                //frameL = 70;
            }
            if ( event.type == sf::Event::Closed )window.close();
            if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Space ) )StartJump();
            if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::A ) )MoveLeft();
            if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::D ) )MoveRight();
            Update();
            window.clear(sf::Color(0,0,250));//azul
            //ImGui::SFML::Render (window);
            for ( int i = 25; i <= ancho ; i += 50 )
            {
                box.setPosition ( i, 500-25 );
                window.draw ( box );
            }
            window.draw(pikachu);
            window.display();
            clock.restart();
        }
    }
}

void MoveLeft()
{
    velocidadX = -12;
    frameL += 70;
    if ( frameL == 350+70 )frameL = 70;
    pikachu.setTextureRect ( sf::IntRect ( frameL, 0, -70, 70 ) );
}
void MoveRight()
{
    velocidadX = 12;
    frameR += 70;
    if ( frameR == 350 )frameR = 0;
    pikachu.setTextureRect ( sf::IntRect ( frameR, 0, 70, 70 ) );
}
void StartJump()
{
    if (!onGround && jumpCounter == 0)
    {
        velocidadY = -vely;
        jumpCounter = 1;
    }
    if(onGround)
    {
        velocidadY = -vely;
        onGround = false;
        jumpCounter = 1;
    }
}
void EndJump()
{
    if(velocidadY > -6)velocidadY = -6;
}
void Update()
{
    velocidadY += gravedad/divisor;
    posicionY += velocidadY/divisor;
    posicionX += velocidadX/divisor;

    if(posicionY > suelo)
    {
        posicionY = suelo;
        velocidadY = 0.0;
        onGround = true;
    }
    if(posicionX > ancho -35)posicionX = ancho -35;
    if(posicionX < 35)posicionX = 35;
    pikachu.setPosition( posicionX, posicionY );
    velocidadX = 0.0;
    if (onGround)jumpCounter = 0;
}
void pivot(sf::Sprite& sprite)
{
    sf::Vector2f pivot;
    pivot.x = sprite.getTextureRect().width / 2.f;
    pivot.y = sprite.getTextureRect().height / 2.f;
    sprite.setOrigin ( pivot );
}
enum SmartButtonState
{
    None = 0,
    Hovered,
    Pressed,
    Released,
    DoubleClicked
};

static SmartButtonState SmartButton(const char* label, ImVec2 size = {0, 0})
{
    bool released = ImGui::Button(label, size);
    if (released) return SmartButtonState::Released;
    if (ImGui::IsItemActive()) return SmartButtonState::Pressed;
    if (ImGui::IsItemHovered()) return SmartButtonState::Hovered;
    return SmartButtonState::None;
}

void menu()
{
    sf::RenderWindow window(sf::VideoMode ( 500, 500, bits ),  nome.c_str());
    window.setFramerateLimit (60);
    ImGui::SFML::Init (window);
    ImGuiIO& io = ImGui::GetIO();
    ImFont* font1 = io.Fonts->AddFontDefault();
    ImFont* font2 = io.Fonts->AddFontFromMemoryTTF(sewer_font,42136,20);
    ImGui::SFML::UpdateFontTexture();
    auto& style = ImGui::GetStyle();
    style.FrameRounding = 4.0f;
    style.WindowBorderSize = 0.0f;
    style.PopupBorderSize = 0.0f;
    style.GrabRounding = 4.0f;
    ImVec4* colors = ImGui::GetStyle().Colors;

    colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled]           = ImVec4(0.73f, 0.75f, 0.74f, 1.00f);
    colors[ImGuiCol_WindowBg]               = ImVec4(0.25f, 0.30f, 0.8f, 0.94f);
    colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border]                 = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
    colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.84f, 0.66f, 0.66f, 0.40f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.84f, 0.66f, 0.66f, 0.67f);
    colors[ImGuiCol_TitleBg]                = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.47f, 0.22f, 0.22f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
    colors[ImGuiCol_MenuBarBg]              = ImVec4(0.34f, 0.16f, 0.16f, 1.00f);
    colors[ImGuiCol_Button]                 = ImVec4(0.47f, 0.22f, 0.22f, 0.65f);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.71f, 0.39f, 0.39f, 0.65f);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent (event))
        {
            ImGui::SFML::ProcessEvent (event);
            if (event.type == sf::Event::Closed)window.close();
        }
        ImGui::SFML::Update (window, deltaClock.restart());
        ImGui::PushFont(font2);

        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Always);
        ImGui::SetNextWindowSize( ImVec2(500,500) );
        ImGui::Begin("Buttons",nullptr,ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse|
                     ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar);
        {
            static const auto size = ImVec2(150, 40);
            static ImVec4 padrao {0.25f, 1.00f, 0.00f, 1.00f};
            static const ImVec4 padrao2 {0.25f, 1.00f, 0.00f, 1.00f};
            static const ImVec4 cor { 0.25f, 1.00f, 0.00f, 0.43f};

            ImGui::PushStyleColor(ImGuiCol_Button, padrao);
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, padrao);
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, padrao);
            ImGui::Text("BEM VINDO AO JOGO DO HERBERT");
            auto state = SmartButton("JOGAR", size);
            if (state == SmartButtonState::Released)game_run();
            ImGui::PopStyleColor(3);

            if (state == SmartButtonState::Pressed)padrao = cor;
            else if (state == SmartButtonState::Hovered)padrao = cor;
            else if (state == SmartButtonState::Released)padrao = cor;
            else  padrao = padrao2;
            if (SmartButton("SAIR", size) == SmartButtonState::Released)window.close();
        }
        ImGui::PopFont();
        ImGui::End();
        window.clear();
        ImGui::SFML::Render (window);
        window.display();
    }
}
