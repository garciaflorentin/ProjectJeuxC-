#include "GameGestion.hpp"
#include <memory>

GameGestion::GameGestion()
{
	currentZoneMusic= -1;
	player = new Player("player1.png", {2, -1});
	player2 = new Player("player2.png", {1, -1});
	/*player->addKey();
		player->addKey();
	player->addKey();
	player->addKey();
*/
	_map = new Map();
	_map->createMap();
	playerVector = new std::vector<Player *>{player, player2};
	forestMusic = new sf::Music;
	townMusic =new sf::Music;
	MountainMusic= new sf::Music;
	BeatchMusic= new sf::Music;
	if (!forestMusic->openFromFile("ForestMood.wav"))
	{
	townMusic =new sf::Music;
	MountainMusic= new sf::Music;
	BeatchMusic= new sf::Music;
	if (!forestMusic->openFromFile("ForestMood.wav"))
	{
	std::cout<<"erreur de chargement de forestMusic"<<std::endl;
	}
	if (!townMusic->openFromFile("TownMood.wav"))
	{
	std::cout<<"erreur de chargement de townMusic"<<std::endl;
	}
	if (!MountainMusic->openFromFile("MountainMood.wav"))
	{
	std::cout<<"erreur de chargement de MountainMusic"<<std::endl;
	}
	if (!BeatchMusic->openFromFile("BeatchMood.ogg"))
	{
	std::cout<<"erreur de chargement de BeatchMusic"<<std::endl;
	}
	
	
	musics.push_back(forestMusic);
	musics.push_back(MountainMusic);
	musics.push_back(townMusic);
	musics.push_back(BeatchMusic);





	}
	if (!townMusic->openFromFile("TownMood.wav"))
	{
	std::cout<<"erreur de chargement de townMusic"<<std::endl;
	}
	if (!MountainMusic->openFromFile("MountainMood.wav"))
	{
	std::cout<<"erreur de chargement de MountainMusic"<<std::endl;
	}
	if (!BeatchMusic->openFromFile("BeatchMood.ogg"))
	{
	std::cout<<"erreur de chargement de BeatchMusic"<<std::endl;
	}
	
	
	musics.push_back(forestMusic);
	musics.push_back(MountainMusic);
	musics.push_back(townMusic);
	musics.push_back(BeatchMusic);





}

GameGestion::~GameGestion()
{
	delete player;
	delete player2;
	delete _map;
	delete forestMusic;
	delete BeatchMusic;
	delete MountainMusic;
	delete townMusic;

	delete BeatchMusic;
	delete MountainMusic;
	delete townMusic;

}

std::vector<Object *> *GameGestion::toDrawUpdate(std::vector<sf::Vector2f> *currentWindow)
{
	return _map->objectToDraw(currentWindow);
}

bool GameGestion::drawProjectile1(std::vector<sf::Vector2f> *currentWindow)
{
	Projectile *_projectile1 = (*playerVector)[0]->getProjectile();
	if (_projectile1->isShot())
	{
		std::cout << "projX=" << (*playerVector)[0]->getProjectile()->getPosition().x << std::endl;
		std::cout << "projY=" << (*playerVector)[0]->getProjectile()->getPosition().y << std::endl;
	}
	if (_projectile1->isShot() && (_projectile1->getPosition().x >= ((*currentWindow)[0].x - 200) && _projectile1->getPosition().y >= ((*currentWindow)[0].y) - 200) && (_projectile1->getPosition().x <= ((*currentWindow)[1].x + 50) && _projectile1->getPosition().y < ((*currentWindow)[1].y) + 50))
	{
		return !((*playerVector)[0]->getProjectile() == nullptr);
	}
	else
	{
		return false;
	}
}

bool GameGestion::drawProjectile2(std::vector<sf::Vector2f> *currentWindow)
{
	Projectile *_projectile2 = (*playerVector)[1]->getProjectile();
	if (_projectile2->isShot())
	{
		std::cout << "projX=" << (*playerVector)[1]->getProjectile()->getPosition().x << std::endl;
		std::cout << "projY=" << (*playerVector)[1]->getProjectile()->getPosition().y << std::endl;
	}
	if (_projectile2->isShot() && (_projectile2->getPosition().x >= ((*currentWindow)[0].x - 200) && _projectile2->getPosition().y >= ((*currentWindow)[0].y) - 200) && (_projectile2->getPosition().x <= ((*currentWindow)[1].x + 50) && _projectile2->getPosition().y < ((*currentWindow)[1].y) + 50))
	{
		return !((*playerVector)[1]->getProjectile() == nullptr);
	}
	else
	{
		return false;
	}
}

bool GameGestion::drawFireballs(std::vector<sf::Vector2f>* currentWindow, std::vector<Projectile*>* toFill) {
	//cout << "Entering drawFireballs()" << endl;

	int indice = 0;

	for (int i=0; i<_map->getMonsters()->size(); i++) {
		//cout << "checking fireballs" << endl;
		if ((*(_map->getMonsters()))[i]->getProjectile() != nullptr) {
			cout << "found fireball" << endl;

			toFill->push_back((*(_map->getMonsters()))[i]->getProjectile());

			if((*toFill)[indice]->isShot()){
				std::cout<<"projX="<<(*toFill)[indice]->getPosition().x<<std::endl;
				std::cout<<"projY="<<(*toFill)[indice]->getPosition().y<<std::endl;
			}

			if (!((*toFill)[indice]->isShot() && ((*toFill)[indice]->getPosition().x >= ((*currentWindow)[0].x - 200) && (*toFill)[indice]->getPosition().y >= ((*currentWindow)[0].y)-200) && ((*toFill)[indice]->getPosition().x <= ((*currentWindow)[1].x+50) && (*toFill)[indice]->getPosition().y < ((*currentWindow)[1].y)+50) ))  {
					//return !((*playerVector)[0]->getProjectile()==nullptr);
					indice--;
					toFill->pop_back();

					cout << "popping back fireball" << endl;
			}

			indice++;
		}
	}

	return (indice > 0);
}

void GameGestion::keyEvent(sf::Event e)
{
	(*playerVector)[0]->setSpeed(_map->getMonsters()->size() / 5);
	float vitesse = (*playerVector)[0]->getSpeed();
	float vitesse = (*playerVector)[0]->getSpeed();
	if (vitesse <= 3)
	{
		(*playerVector)[0]->setSpeed(4);
		vitesse = 4;
	}
	(*playerVector)[1]->setSpeed(_map->getMonsters()->size() / 5);
	vitesse = (*playerVector)[1]->getSpeed();
	if (vitesse <= 3)
	{
		(*playerVector)[1]->setSpeed(4);
		vitesse = 4;
	}

	Player *p1 = (*playerVector)[0];
	Player *p2 = (*playerVector)[1];

if(!(*playerVector)[0]->WeaponIsUsed()){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{ // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) e.key.code == sf::Keyboard::Down
		// std::cout << " D " << std::endl;
		p1->getAnim()->x++;
		p1->getAnim()->y = 0;
		p1->setOrientation(2);
		p1->move({0, vitesse});
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// std::cout << " U " << std::endl;
		p1->getAnim()->x++;
		p1->getAnim()->y = 4;
		p1->setOrientation(0);
		p1->move({0, -vitesse});
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// std::cout << " R " << std::endl;
		p1->getAnim()->x++;
		p1->getAnim()->y = 2;
		p1->setOrientation(3);
		p1->move({vitesse, 0});
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// std::cout << " L " << std::endl;
		p1->getAnim()->x++;
		p1->getAnim()->y = 6;
		p1->setOrientation(1);
		p1->move({-vitesse, 0});
	}
	p1->updateSprite();

}
if(!(*playerVector)[1]->WeaponIsUsed()){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{ // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) e.key.code == sf::Keyboard::Down
		// std::cout << " D " << std::endl;
		p2->getAnim()->x++;
		p2->getAnim()->y = 0;
		p2->setOrientation(2);
		p2->move({0, vitesse});
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		// std::cout << " U " << std::endl;
		p2->getAnim()->x++;
		p2->getAnim()->y = 4;
		p2->setOrientation(0);
		p2->move({0, -vitesse});
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		// std::cout << " R " << std::endl;
		p2->getAnim()->x++;
		p2->getAnim()->y = 2;
		p2->setOrientation(3);
		p2->move({vitesse, 0});
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		// std::cout << " L " << std::endl;
		p2->getAnim()->x++;
		p2->getAnim()->y = 6;
		p2->setOrientation(1);
		p2->move({-vitesse, 0});
	}
		p2->updateSprite();

}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		if(p2->isAlive()) p2->useWand();
		if(p2->isAlive()) p2->useWand();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		if(p1->isAlive()) p1->useBow();
		if(p1->isAlive()) p1->useBow();
	}
}

int GameGestion::updateGame()
{
	Player *p1 = (*playerVector)[0];
	Player *p2 = (*playerVector)[1];
	
	if(p2->getKey() != p1->getKey()){
		int tempo=p2->getKey();
		p2->setKey(p2->getKey()+ p1->getKey());
		p1->setKey(tempo+ p1->getKey());
	
	if(p2->getKey() != p1->getKey()){
		int tempo=p2->getKey();
		p2->setKey(p2->getKey()+ p1->getKey());
		p1->setKey(tempo+ p1->getKey());

	}

	//	fade(BeatchMusic);
	

		if (p1->bowIsUsed())// && !p1->getProjectile()->isShot())
	}

	//	fade(BeatchMusic);
	

		if (p1->bowIsUsed())// && !p1->getProjectile()->isShot())
		{
			p1->useBow();
		}
		p1->getProjectile()->arrowOutOfBounds();

	

	
		if (p2->wandIsUsed())//&& !p1->getProjectile()->isShot())
		if (p2->wandIsUsed())//&& !p1->getProjectile()->isShot())
		{
			p2->useWand();
		}
		p2->getProjectile()->arrowOutOfBounds();
	

	collideProjectileGestion();
	collideMonsterGestion();
	collideWallGestion();


	if ((*playerVector)[0]->getIsInTheCave())
	{
		LimitMapBoss();
	}
	else
	{
		LimitMap();
	}
	checkLifeMonster(player->getKilledallMobs());
	checkLifeMonster(player2->getKilledallMobs());

	if (!player->isAlive() || !player2->isAlive())
	{
		if(!player->isAlive() && !player2->isAlive()){
	
	
			return 3;
		}else if (!player->isAlive()){
			_map->addPlayerDead(player->deadGestion());
			_map->addPlayerDead(player->deadGestion());
			return 1;
		}else{
			_map->addPlayerDead(player2->deadGestion());
			_map->addPlayerDead(player2->deadGestion());
			return 2;
		}
	}
	return 0;
}

void GameGestion::setPlayer(sf::Sprite *sprite)
{
	(*playerVector)[0]->setUpCharacter();
	(*playerVector)[1]->setUpCharacter();
}

// interface colision

int GameGestion::collidePosition(Object *object1, Object *object2)
{
	sf::Sprite sprite1 = *object1->getSprite();
	sf::Sprite sprite2 = *object2->getSprite();

	sf::FloatRect rect1 = sprite1.getGlobalBounds();
	sf::FloatRect rect2 = sprite2.getGlobalBounds();

	if (!rect1.intersects(rect2))
	{
		return -1;
	}

	float overlapX = std::min(rect1.left + rect1.width, rect2.left + rect2.width) - std::max(rect1.left, rect2.left);
	float overlapY = std::min(rect1.top + rect1.height, rect2.top + rect2.height) - std::max(rect1.top, rect2.top);

	if (overlapX > overlapY)
	{
		if (rect1.top < rect2.top)
		{
			//std::cout << "up" << std::endl;
			//std::cout << "up" << std::endl;
			return 1;
		}
		else
		{ // std::cout<<"down"<<std::endl;

			return 2;
		}
	}
	else
	{
		if (rect1.left < rect2.left)
		{ // std::cout<<"left"<<std::endl;

			return 3;
		}
		else
		{ // std::cout<<"right"<<std::endl;

			return 4;
		}
	}
}

void GameGestion::collideWall(Object *o, std::vector<Object *> &wallList, std::vector<int> &info)
{
	// std::cout<<"collideWall"<<std::endl;
	bool collide = false;

	for (int x = 0; x < wallList.size(); x++)
	{

		int colision = collidePosition(o, (wallList)[x]);

		if (colision != -1)
		{
			// std::cout<<"collide: collideWall"<<std::endl;
			info.push_back(x);
			info.push_back(colision);
			collide = true;

			// cout << "Collide = true" << endl;
		}
	}
	if (!collide)
	{
		info.push_back(-1);
		info.push_back(-1);
	}
	// std::cout<<"info size= "<<info.size()<<std::endl;
}

void GameGestion::collideMonster(Object *o, std::vector<Monster *> &wallList, std::vector<int> &info)
{
	// std::cout<<"collideWall"<<std::endl;
	bool collide = false;

	for (int x = 0; x < wallList.size(); x++)
	{

		int colision = collidePosition(o, (wallList)[x]);

		if (colision != -1)
		{
			// std::cout<<"collide: collideMonster"<<"indice="<<x<<std::endl;
			info.push_back(x);
			info.push_back(colision);
			collide = true;
		}
	}
	if (!collide)
	{
		info.push_back(-1);
		info.push_back(-1);
	}
	// std::cout<<"info size= "<<info.size()<<std::endl;
}

void GameGestion::collidePlayer(Object* o, Player*p ,std::vector<int>& info) {
	//std::cout<<"collideWall"<<std::endl;
	bool collide =false;

    //for (int x = 0; x < wallList.size(); x++) {

		int colision =collidePosition(o, p);

        if (colision!=-1) {
			//std::cout<<"collide: collideMonster"<<"indice="<<x<<std::endl;
			info.push_back(0);
			info.push_back(colision);
			collide=true;
            
        }
    //}
	if(!collide){
		info.push_back(-1);
		info.push_back(-1);
	}
    //std::cout<<"info size= "<<info.size()<<std::endl;
}

void GameGestion::LimitMap()
{
	std::vector<float> limit;
	_map->getLimitMap(limit);
	sf::Vector2f newpos;

	if (player->getPosition().x < limit[2])
	{
		newpos = {limit[2], player->getPosition().y};
		player->setPosition(newpos);
	}
	else if (player->getPosition().x >= limit[0])
	{
		newpos = {limit[0], player->getPosition().y};
		player->setPosition(newpos);
	}
	else if (player->getPosition().y > limit[1])
	{
		newpos = {player->getPosition().x, limit[1]};
		player->setPosition(newpos);
	}
	else if (player->getPosition().y < limit[3])
	{
		newpos = {player->getPosition().x, limit[3]};
		player->setPosition(newpos);
	}

	if(player->isAlive() && player2->isAlive()){
	if (player2->getPosition().x < player->getPosition().x-362)

	if(player->isAlive() && player2->isAlive()){
	if (player2->getPosition().x < player->getPosition().x-362)
	{
		newpos = {player->getPosition().x-362, player2->getPosition().y};
		newpos = {player->getPosition().x-362, player2->getPosition().y};
		player2->setPosition(newpos);
	}
	if (player2->getPosition().x >= player->getPosition().x+362)
	if (player2->getPosition().x >= player->getPosition().x+362)
	{
		newpos = {player->getPosition().x+362, player2->getPosition().y};
		newpos = {player->getPosition().x+362, player2->getPosition().y};
		player2->setPosition(newpos);
	}
	if (player2->getPosition().y >player->getPosition().y+271)
	if (player2->getPosition().y >player->getPosition().y+271)
	{
		newpos = {player2->getPosition().x,player->getPosition().y+271};
		newpos = {player2->getPosition().x,player->getPosition().y+271};
		player2->setPosition(newpos);
	}
	if (player2->getPosition().y < player->getPosition().y-271)
	if (player2->getPosition().y < player->getPosition().y-271)
	{
		newpos = {player2->getPosition().x, player->getPosition().y-271};
		newpos = {player2->getPosition().x, player->getPosition().y-271};
		player2->setPosition(newpos);
	}
	}else if(player2->isAlive()){
	}else if(player2->isAlive()){
		if (player2->getPosition().x < limit[2])
	{
		newpos = {limit[2], player2->getPosition().y};
		player2->setPosition(newpos);
	}
	else if (player2->getPosition().x >= limit[0])
	{
		newpos = {limit[0], player2->getPosition().y};
		player2->setPosition(newpos);
	}
	else if (player2->getPosition().y > limit[1])
	{
		newpos = {player2->getPosition().x, limit[1]};
		player2->setPosition(newpos);
	}
	else if (player2->getPosition().y < limit[3])
	{
		newpos = {player2->getPosition().x, limit[3]};
		player2->setPosition(newpos);
	}
	}
}

void GameGestion::LimitMapBoss()
{
	std::vector<float> limit;
	_map->getLimitMapBoss(limit);
	sf::Vector2f newpos;

	if (player->getPosition().x < limit[0])
	{
		newpos = {limit[0], player->getPosition().y};
		player->setPosition(newpos);
	}
	if (player->getPosition().x >= limit[2])
	{
		newpos = {limit[2], player->getPosition().y};
		player->setPosition(newpos);
	}
	if (player->getPosition().y > limit[3])
	{
		newpos = {player->getPosition().x, limit[3]};
		player->setPosition(newpos);
	}
	if (player->getPosition().y < limit[1])
	{
		newpos = {player->getPosition().x, limit[1]};
		player->setPosition(newpos);
	}
	if (player2->getPosition().x < limit[0])
	{
		newpos = {limit[0], player2->getPosition().y};
		player2->setPosition(newpos);
	}
	if (player2->getPosition().x >= limit[2])
	{
		newpos = {limit[2], player2->getPosition().y};
		player2->setPosition(newpos);
	}
	if (player2->getPosition().y > limit[3])
	{
		newpos = {player2->getPosition().x, limit[3]};
		player2->setPosition(newpos);
	}
	if (player2->getPosition().y < limit[1])
	{
		newpos = {player2->getPosition().x, limit[1]};
		player2->setPosition(newpos);
	}
}

void GameGestion::collideWallGestion()
{
	// std::cout<<"collideWallGestion"<<std::endl;
	Player *p1 = (*playerVector)[0];
	Player *p2 = (*playerVector)[1];
	sf::Vector2f newpos;
	std::vector<int> infoPlayer;
	std::vector<int> infoPlayer2;

	std::vector<Object *> wallList;
	wallList = *_map->getWallList();
	collideWall(p1, wallList, infoPlayer);
	collideWall(p2, wallList, infoPlayer2);

	int indice = infoPlayer[0];
	int typeCollide = infoPlayer[1];
	int indice2 = infoPlayer2[0];
	int typeCollide2 = infoPlayer2[1];

	if (indice != -1 && typeCollide != -1)
	{
		switch (typeCollide)
		{ // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {p1->getPosition().x, wallList[indice]->getPosition().y - 48};
			p1->setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {p1->getPosition().x, wallList[indice]->getPosition().y + wallList[indice]->getSprite()->getGlobalBounds().height};
			p1->setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {wallList[indice]->getPosition().x - 48, p1->getPosition().y};
			p1->setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {wallList[indice]->getPosition().x + 48, p1->getPosition().y};
			p1->setPosition(newpos);
			break;
		}
		collideVisitor(p1, wallList[indice]);
	}
	if (indice2 != -1 && typeCollide2 != -1)
	{
		switch (typeCollide2)
		{ // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {p2->getPosition().x, wallList[indice2]->getPosition().y - 48};
			p2->setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {p2->getPosition().x, wallList[indice2]->getPosition().y + wallList[indice2]->getSprite()->getGlobalBounds().height};
			p2->setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {wallList[indice2]->getPosition().x - 48, p2->getPosition().y};
			p2->setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {wallList[indice2]->getPosition().x + 48, p2->getPosition().y};
			p2->setPosition(newpos);
			break;
		}
		collideVisitor(p2, wallList[indice2]);
	}
}

void GameGestion::collideProjectileGestion()
{

	std::vector<int> infoWall;
	std::vector<int> infoWall2;

	std::vector<int> infoMonster;
	std::vector<int> infoMonster2;

	std::vector<Object *> wallList;
	std::vector<Monster *> _monsterList;

	Projectile *_projectile;
	Projectile *_projectile2;

	// = new Projectile(*(*playerVector)[0]->getProjectile());
	// std::shared_ptr<Projectile> _projectile = std::make_shared<Projectile(*(*playerVector)[0]->getProjectile())>();
	_projectile = (*playerVector)[0]->getProjectile();
	_projectile2 = (*playerVector)[1]->getProjectile();
	if (_projectile->isShot() || _projectile2->isShot())
	{

		// std::cout<<"projectilTire"<<std::endl;
		wallList = *_map->getWallList();
		collideWall(_projectile, wallList, infoWall);
		collideWall(_projectile2, wallList, infoWall2);

		_monsterList = *_map->getMonsters();
		collideMonster(_projectile, _monsterList, infoMonster);
		collideMonster(_projectile2, _monsterList, infoMonster2);

		int indice = infoWall[0];
		int typeCollide = infoWall[1];
		int indiceMonster = infoMonster[0];
		int TypeCollideMonster = infoMonster[1];
		int indice2 = infoWall2[0];
		int typeCollide2 = infoWall2[1];
		int indiceMonster2 = infoMonster2[0];
		int TypeCollideMonster2 = infoMonster2[1];

		if (indice != -1 && typeCollide != -1)
		{
			collideVisitor(_projectile, wallList[indice]);
			// delete _projectile;
		}
		if (indiceMonster != -1 && TypeCollideMonster != -1)
		{
			collideVisitor(_projectile, _monsterList[indiceMonster]);
		}
		if (indice2 != -1 && typeCollide2 != -1)
		{
			collideVisitor(_projectile2, wallList[indice2]);
			// delete _projectile;
		}
		if (indiceMonster2 != -1 && TypeCollideMonster2 != -1)
		{
			collideVisitor(_projectile2, _monsterList[indiceMonster2]);
		}
	}
}

void GameGestion::collideMonsterGestion()
{

	Player *p1 = (*playerVector)[0];
	Player *p2 = (*playerVector)[1];
	// std::cout<<"collideWallGestion"<<std::endl;
	sf::Vector2f newpos;
	std::vector<int> infoPlayer;
	std::vector<int> infoPlayer2;

	std::vector<Monster *> _MonsterList;
	_MonsterList = *_map->getMonsters();
	collideMonster(p1, _MonsterList, infoPlayer);
	collideMonster(p2, _MonsterList, infoPlayer2);

	int indice = infoPlayer[0];
	int typeCollide = infoPlayer[1];
	int indice2 = infoPlayer2[0];
	int typeCollide2 = infoPlayer2[1];
	std::vector<int> MonsterToKill;
	/*player->targetInRange(_MonsterList,MonsterToKill);
	for(int i=0;i<MonsterToKill.size();i++){
		//if(player->swordIsUsed()){
		_MonsterList[MonsterToKill[i]]->takeDamage(12);
		//}

	}*/

	if ((indice != -1 && typeCollide != -1))
	{

		// collideVisitor(player,_MonsterList[indice]);
		switch (typeCollide)
		{ // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {player->getPosition().x, _MonsterList[indice]->getPosition().y - 48};
			player->setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {player->getPosition().x, _MonsterList[indice]->getPosition().y + _MonsterList[indice]->getSprite()->getGlobalBounds().height};
			player->setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {_MonsterList[indice]->getPosition().x - 48, player->getPosition().y};
			player->setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {_MonsterList[indice]->getPosition().x + 48, player->getPosition().y};
			player->setPosition(newpos);
			break;
		}
		collideVisitor(player, _MonsterList[indice]);
	}
	if ((indice2 != -1 && typeCollide2 != -1))
	{

		// collideVisitor(player,_MonsterList[indice]);
		switch (typeCollide2)
		{ // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {p2->getPosition().x, _MonsterList[indice2]->getPosition().y - 48};
			p2->setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {p2->getPosition().x, _MonsterList[indice2]->getPosition().y + _MonsterList[indice2]->getSprite()->getGlobalBounds().height};
			p2->setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {_MonsterList[indice2]->getPosition().x - 48, p2->getPosition().y};
			p2->setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {_MonsterList[indice2]->getPosition().x + 48, p2->getPosition().y};
			p2->setPosition(newpos);
			break;
		}
		collideVisitor(p2, _MonsterList[indice2]);
	}
}

void GameGestion::collideVisitor(Object *o1, Object *o2)
{

	o2->collide(o1);
	o1->collide(o2);
}

void GameGestion::updateMobs()
{
	// if (time.getElapsedTime().asMilliseconds() % 5 == 0) {
	// cout << "GameGestion::updateMobs time" << endl;
	_map->updateObjects(player);
	_map->updateObjects(player2);


		
		std::vector<Object*> wallList;
		std::vector<Monster*> monsters;
		wallList = *_map->getWallList();
		monsters = *_map->getMonsters();

		//cout << "updating projectiles" << endl;

		std::vector<Projectile*> fireballs;
		for (int i = 0; i < monsters.size(); i++) {
			//cout << "adding projectile" << endl;
			if (monsters[i]->getProjectile() != nullptr) {
				fireballs.push_back(monsters[i]->getProjectile());

				int curr_ind = fireballs.size()-1;
			
				std::vector<int> infoWall;
				std::vector<int> infoPlayer;

				// cout << "entering arrowOutOfBounds" << std::endl;
				// cout << "Projectile distance: " << fireballs[curr_ind]->getDistance() << endl;
				fireballs[curr_ind]->arrowOutOfBounds();

				if(fireballs[curr_ind]->isShot()) {	
					//std::cout<<"projectilTire"<<std::endl;
					//this->_map->addObject(fireballs[curr_ind]);

					collideWall(fireballs[curr_ind],wallList,infoWall);
					collidePlayer(fireballs[curr_ind],player,infoPlayer);

					int indice =infoWall[0];
					int typeCollide=infoWall[1];
					int indicePlayer=infoPlayer[0];
					int TypeCollidePlayer=infoPlayer[1];



					if(indice!= -1 && typeCollide!= -1){
						std::cout<<"colisionProjectile : GameGestion"<<std::endl;
						collideVisitor(fireballs[curr_ind],wallList[indice]);
						//delete _projectile;
					}
					if(indicePlayer!= -1 && TypeCollidePlayer!= -1){
						collideVisitor(fireballs[curr_ind],player);
					}
				}
			}
		}	
		
		// for (Monster* mnt : monsters) {
		// 	sf::Vector2f newpos;
		// 	std::vector<int> info;

		// 	collideWall(mnt,wallList,info);

		// 	int indice=info[0];
		// 	int typeCollide =info[1];

		// 	if(indice!= -1 && typeCollide!= -1){
		// 		switch (typeCollide){//orientation de la colision
		// 			case -1:
		// 				break;

		// 			case 1:// colision du joueur allant vers le bas
		// 				//on empeche le joueur de traverser le Wall
		// 				newpos = {mnt->getPosition().x,wallList[indice]->getPosition().y-48};
		// 				mnt->setPosition(newpos);
		// 				break;
		// 			case 2:// colision du joueur allant vers la haut
		// 				newpos = {mnt->getPosition().x,wallList[indice]->getPosition().y+wallList[indice]->getSprite()->getGlobalBounds().height};
		// 				mnt->setPosition(newpos);
		// 				break;
		// 			case 3:// colision du joueur allant vers la droite
		// 				newpos = {wallList[indice]->getPosition().x-48,mnt->getPosition().y};
		// 				mnt->setPosition(newpos);
		// 				break;
		// 			case 4:// colision du joueur allant vers le gauche
		// 				newpos =  {wallList[indice]->getPosition().x+48,mnt->getPosition().y};
		// 				mnt->setPosition(newpos);
		// 				break;
		// 		}
		// 		collideVisitor(mnt,wallList[indice]);
	// std::vector<Object *> wallList;
	// std::vector<Monster *> monsters;
	// wallList = *_map->getWallList();
	// monsters = *_map->getMonsters();

	for (Monster *mnt : monsters)
	{
		sf::Vector2f newpos;
		std::vector<int> info;

		collideWall(mnt, wallList, info);

		int indice = info[0];
		int typeCollide = info[1];

		if (indice != -1 && typeCollide != -1)
		{
			switch (typeCollide)
			{ // orientation de la colision
			case -1:
				break;

			case 1: // colision du joueur allant vers le bas
				// on empeche le joueur de traverser le Wall
				newpos = {mnt->getPosition().x, wallList[indice]->getPosition().y - 48};
				mnt->setPosition(newpos);
				break;
			case 2: // colision du joueur allant vers la haut
				newpos = {mnt->getPosition().x, wallList[indice]->getPosition().y + wallList[indice]->getSprite()->getGlobalBounds().height};
				mnt->setPosition(newpos);
				break;
			case 3: // colision du joueur allant vers la droite
				newpos = {wallList[indice]->getPosition().x - 48, mnt->getPosition().y};
				mnt->setPosition(newpos);
				break;
			case 4: // colision du joueur allant vers le gauche
				newpos = {wallList[indice]->getPosition().x + 48, mnt->getPosition().y};
				mnt->setPosition(newpos);
				break;
			}
			collideVisitor(mnt, wallList[indice]);
		}
	}
	//}
}

void GameGestion::checkLifeMonster(std::vector<bool> &control)
{
	control = {true, true, true, true};
	std::vector<Monster *> monsters;
	monsters = *_map->getMonsters();
	std::vector<float> limit;
	_map->getLimitMap(limit);
	std::vector<float> limit;
	_map->getLimitMap(limit);
	for (int i = 0; i < monsters.size(); i++)
	{
		if (monsters[i]->getPosition().x >= 0 && monsters[i]->getPosition().x <= limit[0]/2 && monsters[i]->getPosition().y >= limit[3] && monsters[i]->getPosition().y <= 0)
		if (monsters[i]->getPosition().x >= 0 && monsters[i]->getPosition().x <= limit[0]/2 && monsters[i]->getPosition().y >= limit[3] && monsters[i]->getPosition().y <= 0)
		{
			control[0] = false;
		}
		else if (monsters[i]->getPosition().x >= 0 && monsters[i]->getPosition().x <= limit[0]/2 && monsters[i]->getPosition().y <= limit[1] && monsters[i]->getPosition().y >= 0)
		else if (monsters[i]->getPosition().x >= 0 && monsters[i]->getPosition().x <= limit[0]/2 && monsters[i]->getPosition().y <= limit[1] && monsters[i]->getPosition().y >= 0)
		{
			control[1] = false;
		}
		else if (monsters[i]->getPosition().x >= limit[0]/2 && monsters[i]->getPosition().x <= limit[0] && monsters[i]->getPosition().y <= limit[1] && monsters[i]->getPosition().y >= 0)
		else if (monsters[i]->getPosition().x >= limit[0]/2 && monsters[i]->getPosition().x <= limit[0] && monsters[i]->getPosition().y <= limit[1] && monsters[i]->getPosition().y >= 0)
		{
			control[2] = false;
		}
		else if ((monsters[i]->getPosition().x >= limit[0]/2 && monsters[i]->getPosition().x <= limit[0] && monsters[i]->getPosition().y <=0 && monsters[i]->getPosition().y >= limit[3]))
		else if ((monsters[i]->getPosition().x >= limit[0]/2 && monsters[i]->getPosition().x <= limit[0] && monsters[i]->getPosition().y <=0 && monsters[i]->getPosition().y >= limit[3]))
		{
			control[3] = false;
		}
	}
}

void GameGestion::musicGestion(){
	BeatchMusic->setVolume(100);
	//BeatchMusic->setLoop(true);
	BeatchMusic->play();
	/*
	    const int NUM_ZONES = 4;


    // Initialisation des zones et des musiques correspondantes
	std::vector<float> limit;
	_map->getLimitMap(limit);
    sf::IntRect zones[NUM_ZONES] = {
        sf::IntRect(0, limit[3],limit[0]/2, 0),    // Zone 1
        sf::IntRect(50, 0, limit[0]/2, limit[1]),   // Zone 2
        sf::IntRect(limit[0]/2,0, limit[0], limit[1]),   // Zone 3
        sf::IntRect(limit[0]/2,0, limit[0], limit[3])   // Zone 4
    };

    for (int i = 0; i < NUM_ZONES; ++i)
    {
        musics[i]->setLoop(true);
        musics[i]->setVolume(0); // Démarre avec un volume initial faible
        musics[i]->play();
    }

	currentZoneMusic=-1;

    // Boucle principale du jeu
        // Mettre à jour la position du joueur
        sf::Vector2f playerPosition(player->getPosition().x, player->getPosition().y);

        // Trouver la zone actuelle
        int newZoneIndex = -1;
        for (int i = 0; i < NUM_ZONES; ++i)
        {
            if (zones[i].contains(static_cast<int>(playerPosition.x), static_cast<int>(playerPosition.y)))
            {
                newZoneIndex = i;
				std::cout<<"zone="<<i<<std::endl;
                break;
            }
        }

        // Si le joueur a changé de zone
        if (newZoneIndex != currentZoneMusic)
        {
            // Transition musicale
            if (currentZoneMusic != -1)
            {
                sf::Music& previousMusic = *musics[currentZoneMusic];
                sf::Music& newMusic = *musics[newZoneIndex];

                // Fade-out de la musique actuelle
                for (int fadeStep = 10; fadeStep >= 0; --fadeStep)
                {
                    float volume = fadeStep * 10.0f;
                    previousMusic.setVolume(volume);
                    sf::sleep(sf::milliseconds(50)); // Attendre avant chaque ajustement de volume
                }

                // Fade-in de la nouvelle musique
                for (int fadeStep = 0; fadeStep <= 10; ++fadeStep)
                {
                    float volume = fadeStep * 10.0f;
                    newMusic.setVolume(volume);
                    sf::sleep(sf::milliseconds(50)); // Attendre avant chaque ajustement de volume
                }
            }

            currentZoneMusic = newZoneIndex;
        }
		*/


}

void GameGestion::musicFade(sf::Music* music){
    music->setLoop(true);  // Désactiver la lecture en boucle automatique
    music->setVolume(100);  // Définir le volume initial de la musique
     sf::Time fadeDuration = sf::seconds(2.0f);  // Durée du fondu en secondes
    sf::Time fadeDelay = sf::seconds(0.1f);     // Délai entre chaque étape du fondu
    if (music->getStatus() == sf::SoundSource::Playing){

        // Vérifier si la musique est en train de se terminer
        if (music->getPlayingOffset() + fadeDuration >= music->getDuration())
        {
            // Calculer le volume en fonction du temps restant avant la fin
            float fadeFactor = 1.0f - ((music->getDuration() - music->getPlayingOffset()) / fadeDuration);
            music->setVolume(100 * fadeFactor);
        }

        sf::sleep(fadeDelay);
    }else{
    music->stop();
    music->play();
    }

    
}



Map* GameGestion::getMap(){
		return _map;
	}

	const int GameGestion::getObjectSize() const {
		return player->getBlockSize();
	}

	std::vector< Player*>* GameGestion::getPlayerVector() {
		return playerVector;
	}






void GameGestion::musicGestion(){
	BeatchMusic->setVolume(100);
	//BeatchMusic->setLoop(true);
	BeatchMusic->play();
	/*
	    const int NUM_ZONES = 4;


    // Initialisation des zones et des musiques correspondantes
	std::vector<float> limit;
	_map->getLimitMap(limit);
    sf::IntRect zones[NUM_ZONES] = {
        sf::IntRect(0, limit[3],limit[0]/2, 0),    // Zone 1
        sf::IntRect(50, 0, limit[0]/2, limit[1]),   // Zone 2
        sf::IntRect(limit[0]/2,0, limit[0], limit[1]),   // Zone 3
        sf::IntRect(limit[0]/2,0, limit[0], limit[3])   // Zone 4
    };

    for (int i = 0; i < NUM_ZONES; ++i)
    {
        musics[i]->setLoop(true);
        musics[i]->setVolume(0); // Démarre avec un volume initial faible
        musics[i]->play();
    }

	currentZoneMusic=-1;

    // Boucle principale du jeu
        // Mettre à jour la position du joueur
        sf::Vector2f playerPosition(player->getPosition().x, player->getPosition().y);

        // Trouver la zone actuelle
        int newZoneIndex = -1;
        for (int i = 0; i < NUM_ZONES; ++i)
        {
            if (zones[i].contains(static_cast<int>(playerPosition.x), static_cast<int>(playerPosition.y)))
            {
                newZoneIndex = i;
				std::cout<<"zone="<<i<<std::endl;
                break;
            }
        }

        // Si le joueur a changé de zone
        if (newZoneIndex != currentZoneMusic)
        {
            // Transition musicale
            if (currentZoneMusic != -1)
            {
                sf::Music& previousMusic = *musics[currentZoneMusic];
                sf::Music& newMusic = *musics[newZoneIndex];

                // Fade-out de la musique actuelle
                for (int fadeStep = 10; fadeStep >= 0; --fadeStep)
                {
                    float volume = fadeStep * 10.0f;
                    previousMusic.setVolume(volume);
                    sf::sleep(sf::milliseconds(50)); // Attendre avant chaque ajustement de volume
                }

                // Fade-in de la nouvelle musique
                for (int fadeStep = 0; fadeStep <= 10; ++fadeStep)
                {
                    float volume = fadeStep * 10.0f;
                    newMusic.setVolume(volume);
                    sf::sleep(sf::milliseconds(50)); // Attendre avant chaque ajustement de volume
                }
            }

            currentZoneMusic = newZoneIndex;
        }
		*/


}

void GameGestion::musicFade(sf::Music* music){
    music->setLoop(true);  // Désactiver la lecture en boucle automatique
    music->setVolume(100);  // Définir le volume initial de la musique
     sf::Time fadeDuration = sf::seconds(2.0f);  // Durée du fondu en secondes
    sf::Time fadeDelay = sf::seconds(0.1f);     // Délai entre chaque étape du fondu
    if (music->getStatus() == sf::SoundSource::Playing){

        // Vérifier si la musique est en train de se terminer
        if (music->getPlayingOffset() + fadeDuration >= music->getDuration())
        {
            // Calculer le volume en fonction du temps restant avant la fin
            float fadeFactor = 1.0f - ((music->getDuration() - music->getPlayingOffset()) / fadeDuration);
            music->setVolume(100 * fadeFactor);
        }

        sf::sleep(fadeDelay);
    }else{
    music->stop();
    music->play();
    }

    
}



Map* GameGestion::getMap(){
		return _map;
	}

	const int GameGestion::getObjectSize() const {
		return player->getBlockSize();
	}

	std::vector< Player*>* GameGestion::getPlayerVector() {
		return playerVector;
	}




