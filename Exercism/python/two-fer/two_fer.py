def two_fer(name=''):
    if name == '':
        return 'One for you, one for me.'
    return 'One for {}, one for me.'.format(name)
