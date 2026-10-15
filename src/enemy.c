#include "../so_long.h"

void lose_game(t_data *data) {
  ft_printf("\x1B[31m💀 Game Over! You were caught by an enemy!\x1B[0m\n");
  ft_quit_game(data);
}

void ft_find_enemy(t_data *data) {
  int i;
  int j;

  data->enemy.exists = 0;
  data->enemy.x = 0;
  data->enemy.y = 0;
  data->enemy.dir = 1;
  data->enemy.timer = 0;
  i = -1;
  while (++i < data->line) {
    j = -1;
    while (++j < data->col) {
      if (data->map[i][j] == 'A') {
        data->enemy.x = j;
        data->enemy.y = i;
        data->enemy.exists = 1;
        data->map[i][j] = '0';
        return;
      }
    }
  }
}

static int is_valid_tile(t_data *data, int x, int y) {
  if (x < 0 || x >= data->col || y < 0 || y >= data->line)
    return (0);
  if (data->map[y][x] == '1')
    return (0);
  return (1);
}

static int ft_choose_dir(t_data *data, int x, int y, int dir) {
  static const int dx[4] = {0, 1, 0, -1};
  static const int dy[4] = {-1, 0, 1, 0};
  int f;
  int r;
  int l;

  f = is_valid_tile(data, x + dx[dir], y + dy[dir]);
  r = is_valid_tile(data, x + dx[(dir + 1) % 4], y + dy[(dir + 1) % 4]);
  l = is_valid_tile(data, x + dx[(dir + 3) % 4], y + dy[(dir + 3) % 4]);
  data->seed = data->seed * 1103515245 + 12345;
  if (f && (r || l) && ((data->seed / 65536) % 100 < 25))
    f = 0;
  if (f)
    return (dir);
  if (r && l && ((data->seed / 65536) % 2 == 0))
    return ((dir + 1) % 4);
  if (r && l)
    return ((dir + 3) % 4);
  if (r)
    return ((dir + 1) % 4);
  if (l)
    return ((dir + 3) % 4);
  if (is_valid_tile(data, x + dx[(dir + 2) % 4], y + dy[(dir + 2) % 4]))
    return ((dir + 2) % 4);
  return (dir);
}

void ft_enemy_patrol(t_data *data) {
  static const int dx[4] = {0, 1, 0, -1};
  static const int dy[4] = {-1, 0, 1, 0};
  int new_dir;
  int nx;
  int ny;

  if (!data->enemy.exists)
    return;
  new_dir = ft_choose_dir(data, data->enemy.x, data->enemy.y, data->enemy.dir);
  data->enemy.dir = new_dir;
  nx = data->enemy.x + dx[new_dir];
  ny = data->enemy.y + dy[new_dir];
  if (is_valid_tile(data, nx, ny)) {
    data->enemy.x = nx;
    data->enemy.y = ny;
  }
  if (data->enemy.x == data->player.x && data->enemy.y == data->player.y)
    lose_game(data);
}
