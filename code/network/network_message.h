/* date = February 3rd 2022 8:33 pm */

#ifndef NETWORK_MESSAGE_H
#define NETWORK_MESSAGE_H

enum PlayerMove_Type
{
    PlayerMove_None,
    PlayerMove_PlayCard,
    PlayerMove_QuestionCredibility,
};

typedef u8 Compact_Card_Type;

enum MessageType
{
    // NOTE(fakhri): player messages here
    PlayerMessage_ConnectToHost,
    PlayerMessage_Username,
    PlayerMessage_FetchHosts,
    PlayerMessage_StartHostServer,
    PlayerMessage_StopHostServer,
    PlayerMessage_PlayerMove,
    
    // NOTE(fakhri): Host messages here
    HostMessage_InvalidUsername,
    HostMessage_HostFull,
    HostMessage_NewPlayerJoined,
    HostMessage_ConnectedPlayersList,
    HostMessage_ShuffledDeck,
    HostMessage_ChangePlayerTurn,
    HostMessage_PlayerWon,
    HostMessage_PlayerMove,
};

struct Hosts_Storage;
struct Player;

struct PlayerMove
{
    PlayerMove_Type type;
    Compact_Card_Type actual_card;
    Compact_Card_Type declared_card;
};

#define MAX_PLAYER_COUNT (4u)
#define CARDS_PER_PLAYER (13)
#define DECK_CARDS_COUNT (MAX_PLAYER_COUNT * CARDS_PER_PLAYER)
#define InvalidePlayerID MAX_PLAYER_COUNT

struct Message
{
    MessageType type;
    u8 buffer[128];
    union
    {
        struct
        {
            // NOTE(fakhri): connect to host message
            String8 server_address;
        };
        struct 
        {
            // NOTE(fakhri): player usernames message
            String8 username;
        };
        struct 
        {
            // NOTE(fakhri): connected players usernames message
            String8 players_usernames[MAX_PLAYER_COUNT];
            u32 players_count;
        };
        struct 
        {
            // NOTE(fakhri): new player joined message
            String8 new_username;
            PlayerID new_player_id;
        };
        struct 
        {
            // NOTE(fakhri): compact deck message
            Compact_Card_Type *compact_deck;
            u32 compact_cards_count;
        };
    };
};

#endif //NETWORK_MESSAGE_H
