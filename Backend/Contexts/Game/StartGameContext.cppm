export module StartGameContext;
import <string>;
import <vector>;

export import StartGameRequest;
export import StartGameResponse;

export class StartGameContext
{
public:
    static StartGameResponse StartGame(const StartGameRequest& request);
};

StartGameResponse StartGameContext::StartGame(const StartGameRequest& request)
{
    
}
