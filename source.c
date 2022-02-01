// TAD AGENDA

// TAD evento

int main(int argc, char const *argv[]) {
  /* code */
  agenda = criarAgenda();
  novo = lerDados(ent01.in);
  evento = criarEvento(novo->tipo, novo->tempo, novo);
  agendar(agenda, evento);

  while (!vaziaAgenda(agenda)) {
    evento = proximoevento(agenda);
    relogio = evento->tempo;
    if (evento->tipo == 'C'){
      // acões relacionada ao evento chegada de cliente
      // inserir na fila
      cliente = evento->carga;
      inserirNaFila(clientes, cliente);
      if (tamanhoFila(clientes) == 1)&&(CAIXALIVRE(PDVs)){
        evento = criarEvento('I', relogio, NULL);
        agendar(agenda, evento);
      }
    }else if(evento->tipo == 'S'){
      // acões relacionadas ao evento suspensao de atendimento
      pdv = evento->carga;
      pdv->status = 'S';
      // Precisa completar as ações de suspensão de ATENDIMENTO
      // Agendar quando o caixa retoma o atendimento
      
    }else if(evento->tipo == 'I'){
      // descobrir o PDV ocioso (RR)
      pdv=proximoPDV(PDV);
      if (pdv!=NULL){
        // retirar cliente;
        cliente = desenfileirar(clientes)

        ///agendar o final do atendimento
        tempo = relogio + passarCompras + pagamento;
        evento=criarEvento('F', tempo, pdv);
        agendar(agenda, evento);
      }
    }else if(evento->tipo == 'F'){ // final de atendimento
      // evento de final de atendimento
      /// cliente = desenfileirar(clientes)
      pdv = evento->carga;
      pdv->status = 'L';
      if (!vazia(clientes)){
          evento = criarEvento('I', relogio, NULL);
          agendar(agenda, evento);
        }
    }
    /* code */
  }
  return 0;
}