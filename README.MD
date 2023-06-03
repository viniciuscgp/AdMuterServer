# AdMuterServer

O AdMuterServer é uma aplicação de controle de volume versátil e eficaz para máquinas Windows, implementada utilizando o protocolo UDP (User Datagram Protocol). Ele recebe comandos UDP para silenciar e reativar o volume do sistema conforme a instrução recebida. A execução desses comandos é feita através do `nircmd.exe`, uma ferramenta de linha de comando poderosa que permite controlar várias funcionalidades do sistema.

## Protocolo UDP

O protocolo UDP é ideal para esse tipo de aplicação devido à sua natureza livre de conexão e à sua eficiência na entrega de pequenas quantidades de dados. Com o UDP, os pacotes de dados são enviados sem a necessidade de uma conexão prévia, permitindo uma entrega rápida e eficiente dos comandos. Essa eficiência faz do AdMuterServer uma solução rápida e responsiva para controle de volume.

## Expansibilidade

O AdMuterServer foi projetado com a expansibilidade em mente. Embora o escopo atual esteja focado em comandos de mute e unmute, a estrutura da aplicação permite a inclusão de novos comandos com facilidade. Com pequenas modificações, é possível expandir a gama de comandos suportados para incluir outras funcionalidades do `nircmd.exe` ou até mesmo integrar outras ferramentas de linha de comando.

## Compilação

O sistema de construção do projeto é baseado em um arquivo Make. Para compilar o projeto, você precisa seguir os seguintes passos:

1. Instale um ambiente compatível com Make, como [GNU Make](https://www.gnu.org/software/make/) ou o subsistema Linux para Windows.
2. Navegue até a pasta do projeto.
3. Execute o comando `make` no terminal.

Isso compilará o código e criará o executável.

## Utilização

Para utilizar o AdMuterServer, siga as etapas abaixo:

1. Inicie o servidor executando o arquivo binário criado na etapa de compilação.
2. Envie comandos UDP para o endereço e porta em que o servidor está rodando. Os comandos suportados são "mute" e "unmute".

## nircmd.exe

O AdMuterServer usa o `nircmd.exe` para executar comandos de sistema. O NirCmd é uma pequena ferramenta de linha de comando que permite que você faça algumas ações úteis sem exibir qualquer interface de usuário. Ele é usado aqui para controlar o volume do sistema.

Você pode baixar e aprender mais sobre o `nircmd.exe` [aqui](https://www.nirsoft.net/utils/nircmd.html).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para enviar Pull Requests. Se você deseja adicionar novos comandos ou funcionalidades, por favor, consulte a seção de Expansibilidade acima.

## Licença

Este projeto está licenciado sob a licença MIT.

---

Espero que você ache o AdMuterServer útil. Se tiver alguma dúvida ou sugestão, não hesite em abrir uma issue.