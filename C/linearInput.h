    FILE *inputs = fopen("inputs/linearEquations.in","r");
    if (!inputs) {
        perror("fopen");
        return 1;
    }
    fscanf(inputs,"%d",&n);
    double coeffs[n][n+1];
    printf("%d\n",n);

    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            fscanf(inputs,"%lf",&coeffs[i][j]);
            printf(" %lf ",coeffs[i][j]);
        }
        printf("\n");
    }
    fclose(inputs);